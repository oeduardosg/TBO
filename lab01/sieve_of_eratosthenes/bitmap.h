/** Define um TAD representando um mapa de bits.
 * @file bitmap.h
 * @author Joao Paulo Andrade Almeida (jpalmeida@inf.ufes.br)
 */

#ifndef BITMAP_H_
#define BITMAP_H_

/**
 * Estrutura para representar um mapa de bits.
 */
typedef struct map bitmap;

unsigned char* bitmapGetContents(bitmap* bm);
unsigned int bitmapGetMaxSize(bitmap* bm);
unsigned int bitmapGetLength(bitmap* bm);
bitmap* bitmapInit(unsigned int max_size);
unsigned char bitmapGetBit(bitmap* bm, unsigned int index);
void bitmapAppendLeastSignificantBit(bitmap* bm, unsigned char bit);
void bitmapLibera (bitmap* bm);
void bitmapSetBit(bitmap* bm, unsigned int index, unsigned char bit);
void bitmapSetContents(bitmap* bm, unsigned char* contents);
void bitmapSetLength(bitmap* bm, unsigned int lenght);

#endif /*BITMAP_H_*/
