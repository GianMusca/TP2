#ifndef PISO_H
#define PISO_H

typedef enum { SUCIO, LIMPIO } tileType;
typedef unsigned int uint;

tileType* createFloor(uint width, uint height);
void destroyFloor(tileType*);
void cleanTile(tileType* floor, uint x, uint y, uint width);
bool isFloorClean(tileType* floor, uint width, uint height);

#endif
