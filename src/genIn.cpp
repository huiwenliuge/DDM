#include "Base.hpp"
#include <cstring>

int main(int argc,char** argv){

    char* path = (char*)calloc(sizeof(char),51);
    int length = strlen(argv[2]);
    FILE* fp = NULL;
    float sum=0.0;
    while(length>0){
        sprintf(path,"%s%cout%c",argv[1],argv[2][length-1],'\0');
        sum+=readInparm(path);
        length--;
    }

    length = strlen(argv[3]);
    while(length>0){
        sprintf(path,"%s%cin%c",argv[1],argv[3][length-1],'\0');
        prtOutparm(sum,path);
        length--;
    }

}