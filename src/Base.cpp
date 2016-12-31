#include "Base.hpp"

void freeSelf(Self sl){
    Self stmp=sl->next;
    free(sl->cellname);
    free(sl);
    while(stmp){
        free(stmp->cellname);
        sl=stmp;
        stmp=stmp->next;
        free(sl);
    }
}

float readInparm(const char* path){
    char* path_in=(char*)malloc(sizeof(char)*51);
    sprintf(path_in,"%s%s%c",path,"in",'\0');
    FILE* fp = fopen(path_in,"r");
    float ret;
    fscanf(fp,"#%f\n",&ret);
    free(path_in);
    fclose(fp);
    return ret;
}

float readOutparm(const char* path){
    char* path_out=(char*)malloc(sizeof(char)*51);
    sprintf(path_out,"%s%s%c",path,"out",'\0');
    FILE* fp=fopen(path_out,"r");
    float ret;
    fscanf(fp,"#%f#\n",&ret);
    free(path_out);
    fclose(fp);
    return ret;
}

void prtOutparm(float out,const char* path){
    char* path_out=(char*)malloc(sizeof(char)*51);
    sprintf(path_out,"%s%s%c",path,"out",'\0');
    FILE* fp = fopen(path_out,"w");
    free(path_out);
    fclose(fp);
    fprintf(fp,"#%.6f#",out);
}

void resetInparm(const char* path){
    char* path_in=(char*)malloc(sizeof(char)*51);
    sprintf(path_in,"%s%s%c",path,"in",'\0');
    FILE* fp = fopen(path_in,"w");
    fprintf(fp,"#%.6f#",(float)0.0);
    free(path_in);
    fclose(fp);
}

Self readSelfparm(const char* path){
    char* path_self=(char*)malloc(sizeof(char)*51);
    sprintf(path_self,"%s%s%c",path,"self",'\0');
    FILE* fp = fopen(path_self,"r");
    float fac;
    char* name = (char*)calloc(sizeof(char),51);
    Self ret,tmp;
    ret=NULL;
    while(fscanf(fp,"%s #%f#\n",name,&fac)!=-1){
        std::cout<<name<<" "<<fac<<std::endl;
        tmp=(Self)malloc(sizeof(self));
        tmp->factor=fac;
        tmp->cellname=name;
        tmp->next=ret;
        tmp->prev=NULL;
        if(ret) ret->prev=tmp;
        ret=tmp;
        name = (char*)calloc(sizeof(char),51);
    }
    free(name);
    free(path_self);
    fclose(fp);
    return ret;
}

void prtSelfparm(Self tcell,const char* path){
    char* path_self=(char*)malloc(sizeof(char)*51);
    sprintf(path_self,"%s%s%c",path,"self",'\0');
    FILE* fp = fopen(path_self,"w");
    while(tcell){
        fprintf(fp,"%s #%f#\n",tcell->cellname,tcell->factor);
        tcell=tcell->next;
    }
    free(path_self);
    fclose(fp);
}