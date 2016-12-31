#ifndef BASE_INC
#define BASE_INC

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>

struct self{
    char* cellname;
    float factor;
    self* next;
    self* prev;
};

typedef self* Self;

void freeSelf(Self sl);

float readInparm(const char* path);
float readOutparm(const char* path);
void prtOutparm(float var,const char* path);
void resetInparm(const char* path);

Self readSelfparm(const char* path);
void prtSelfparm(Self tcell,const char* path);

#endif