#ifndef BASE_INC
#define BASE_INC

#include <iostream>
#include <fstream>
#include <stdlib.h>

struct self{
    char* cellname;
    float factor;
    self* next;
};

typedef self* Self;

float readInparm(const char* path);
void prtOutparm(float var,const char* path);
void resetInparm(const char* path);

Self readSelfparm(const char* path);
void prtSelfparm(Self tcell,const char* path);

#endif