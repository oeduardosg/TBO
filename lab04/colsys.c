#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "canvas.h"
#include "colsys.h"
#include "event.h"
#include "particle.h"
#include "PQ.h"

// Número de eventos de redraw por pulso de clock.
#define Hz (0.5)

// Fila de prioridade dos eventos de colisão.
static PQ *pq;
// Tempo de atual de simulação.
static double t;
// Limite de tempo da simulação.
static double limit;
// Vetor de partículas.
static Particle* *particles;
// Quantidade de partículas.
static int N;
// Indicador se uma interface gráfica está em uso.
static bool use_gui;

/*
 * Inicializa a simulação com o número dado de partículas e o tempo máximo.
 */
void system_init(int max_N, double max_limit, bool gui) {
    N = max_N;
    t = 0.0;
    limit = max_limit;
    use_gui = gui;
    pq = PQ_create(N*N*N); // Super estimando o número máximo de eventos.
    particles = malloc(N * sizeof(Particle*));
    for (int i = 0; i < N; i++) {
        particles[i] = NULL;
    }
}

/*
 * Termina a simulação, liberando a memória usada.
 */
void system_finish() {
    PQ_destroy(pq);
    for (int i = 0; i < N; i++) {
        destroy_particle(particles[i]);
    }
    free(particles);
    printf("SIMULATION: Finished.\n");
}

/*
 * Carrega as informações das partículas do arquivo dado.
 */
void load_particles(char *file_name) {
    FILE *fp = fopen(file_name, "r");

    if (fp == NULL) {
        fprintf(stderr, "ERROR: Could not open file '%s'!\n", file_name);
        exit(EXIT_FAILURE);
    }

    int dummy;
    fscanf(fp, "%d\n", &dummy);
    for (int i = 0; i < N; i++) {
        double rx, ry, vx, vy, radius, mass;
        int r, g, b;
        fscanf(fp, "%lf %lf %lf %lf %lf %lf %d %d %d\n",
               &rx, &ry, &vx, &vy, &radius, &mass, &r, &g, &b);
        particles[i] = create_particle(rx, ry, vx, vy, radius, mass, r, g, b);
    }

    fclose(fp);
}

/*
 * Cria um conjunto de partículas com características aleatórias.
 */
void create_random_particles() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand48(tv.tv_usec);

    for (int i = 0; i < N; i++) {
        particles[i] = create_random_particle();
    }
}

/*
 * Atualiza a fila de prioridade com todos os novos eventos para a partícula.
 */
void predict(Particle *p) {
    // TODO: Implemente essa função que prevê todos os próximos eventos para a
    //       a partícula 'p' dada. Essa função deve prever tanto os eventos
    //       de colisão de 'p' com outras partículas quanto com as paredes.
    //
    //       Todos os eventos são previstos de forma INDEPENDENTE. Isso quer
    //       dizer que o evento é criado assumindo que nenhuma outra colisão
    //       com 'p' vai ocorrer. Por isso que o evento deve ser testado
    //       quando ele for retirado da fila. Somente aqueles eventos que não
    //       foram invalidados devem ser de fato executados.
    //
    //       Utilize as funções 'time_to_hit[...]' em 'particle.h' para obter
    //       o tempo de cada colisão.
    //
    //       Faça os seguintes passos nessa função.

    // - Se p é nulo, retorne imediatamente.
    if(!p) return;

    // - Calcule o tempo de colisão de 'p' com todas as partículas do vetor
    //   de partículas usando a função 'time_to_hit'. Se a colisão vai ocorrer
    //   dentro do limite de tempo da simulação (variável global 'limit'), crie
    //   um evento e insira-o na fila.
    for(int i = 0; i < N; i++) {
        double time = time_to_hit(p, particles[i]);
        if((time + t) < limit) PQ_insert(pq, create_event(time + t, p, particles[i]));
    }

    // - Calcule o tempo de colisão de 'p' com a parede vertical utilizando a
    //   função 'time_to_hit_vertical_wall'. Se a colisão vai ocorrer
    //   dentro do limite de tempo da simulação (variável global 'limit'), crie
    //   um evento e insira-o na fila. Conforme explicado no comentário da
    //   função 'create_event' em 'event.h', um evento de colisão com uma
    //   parece vertical é criado passando-se a SEGUNDA partícula para a função
    //   como nula.
    double time_vertical = time_to_hit_vertical_wall(p);
    if((time_vertical + t) < limit) PQ_insert(pq, create_event(time_vertical + t, p, NULL));

    // - Calcule o tempo de colisão de 'p' com a parede horizontal utilizando a
    //   função 'time_to_hit_horizontal_wall'. Se a colisão vai ocorrer
    //   dentro do limite de tempo da simulação (variável global 'limit'), crie
    //   um evento e insira-o na fila. Conforme explicado no comentário da
    //   função 'create_event' em 'event.h', um evento de colisão com uma
    //   parece vertical é criado passando-se a PRIMEIRA partícula para a função
    //   como nula.
    double time_horizontal = time_to_hit_horizontal_wall(p);
    if((time_horizontal + t) < limit) PQ_insert(pq, create_event(time_horizontal + t, NULL, p));
}

/*
 * Redesenha todas as partículas.
 */
void redraw() {
    if (!use_gui) return;
    canvas_clear();
    for (int i = 0; i < N; i++) {
        draw_particle(particles[i]);
    }
    canvas_show();
    canvas_pause(20);
    if (t < limit) {
        Event *e = create_event(t + 1.0 / Hz, NULL, NULL);
        PQ_insert(pq, e);
    }
}

/*
 * Prepara a simulação para ser iniciada.
 */
void prepare() {
    // Inicializa a fila com eventos de colisão e de redraw.
    for (int i = 0; i < N; i++) {
        predict(particles[i]);
    }
    Event *redraw_e = create_event(0, NULL, NULL); // Evento de redraw.
    PQ_insert(pq, redraw_e);
    printf("SIMULATION: Ready to start.\n");
}

/*
 * Simula o sistema de partículas pelo período de tempo especificado.
 */
void simulate() {
    printf("SIMULATION: Starting main loop.\n");

    // TODO: Implemente aqui o loop principal da simulação orientada a eventos.
    //       Repita os seguintes passos enquanto a fila de eventos não estiver
    //       vazia e o tempo de simulação (variável global 't') não ultrapassar
    //       o limite de tempo (variável global 'limit').

    while (t < limit && !PQ_is_empty(pq)) {

    // - Retire o primeiro evento da fila. Se ele não for válido descarte-o.
    //   (Lembre de liberar a memória do evento.)
        Event * e = PQ_delmin(pq);

        if(!is_valid(e)) {
            destroy_event(e);
            continue;
        }

    // - Se o evento for válido, avançe o tempo da simulação para o tempo do
    //   evento. Percorra todo o vetor de partículas atualizando a posição das
    //   partículas através da função 'move_particle'. O parâmetro 'dt' dessa
    //   função é a diferença de tempo entre o valor de 't' antigo e o tempo
    //   do evento.
        double time_b = t;
        t = get_time(e);
        double dif = t - time_b;

        for(int i = 0; i < N; i++) move_particle(particles[i], dif);


    // - Processe o evento. (Veja os tipos de eventos no comentário da
    //   função 'create_event' em 'event.h'.) Utilize as funções 'bounce_off'
    //   para calcular a colisão da(s) partícula(s) do evento. Se o evento
    //   for o caso especial de redesenho da tela, chame a função 'redraw()'.
        Particle * a = get_A(e), * b = get_B(e);

        if(!a && !b) redraw();
        else if(!b) bounce_off_vertical_wall(a);
        else if(!a) bounce_off_horizontal_wall(b);
        else bounce_off(a, b);

        destroy_event(e);

    // - Por fim, atualize a fila com as novas colisões envolvendo as
    //   partículas do evento, chamando a função predict() com os argumentos
    //   adequados.

        predict(a);
        predict(b);

    }

    printf("SIMULATION: Exiting main loop.\n");
}
