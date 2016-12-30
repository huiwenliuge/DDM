#include "Base.hpp"

float readInparm(const char* path){
    FILE* fp = fopen(path,"r");
    float ret;
    fscanf(fp,"#%f\n",&ret);
    return ret;
}

void prtOutparm(float out,const char* path){
    FILE* fp = fopen(path,"w");
    fprintf(fp,"#%.6f#",out);
}