#include "Base.hpp"

float readInparm(const char* path){
    char* path_in=(char*)malloc(sizeof(char)*51);
    sprintf(path_in,"%s%s\n",path,"in");
    FILE* fp = fopen(path_in,"r");
    float ret;
    fscanf(fp,"#%f\n",&ret);
    return ret;
}

void prtOutparm(float out,const char* path){
    char* path_out=(char*)malloc(sizeof(char)*51);
    sprintf(path_out,"%s%s\n",path,"out");
    FILE* fp = fopen(path_out,"w");
    fprintf(fp,"#%.6f#",out);
}

void resetInparm(const char* path){
    char* path_in=(char*)malloc(sizeof(char)*51);
    sprintf(path_in,"%s%s\n",path,"in");
    FILE* fp = fopen(path_in,"w");
    fprintf(fp,"#%.6f#",(float)0.0);
}

Self readSelfparm(const char* path){
    FILE* fp = fopen(path,"r");
    float fac;
    char* name = (char*)calloc(sizeof(char),51);
    Self ret,tmp;
    ret=NULL;
    while(fscanf(fp,"%s: %f\n",name,&fac)!=-1){
        tmp=(Self)malloc(sizeof(self));
        tmp->factor=fac;
        tmp->cellname=name;
        tmp->next=ret;
        ret=tmp;
        name = (char*)calloc(sizeof(char),51);
    }
    return ret;
}

void prtSelfparm(Self tcell,const char* path){
    FILE* fp = fopen(path,"w");
    while(tcell){
        fprintf(fp,"%s: %f\n",tcell->cellname,tcell->factor);
        tcell=tcell->next;
    }
}