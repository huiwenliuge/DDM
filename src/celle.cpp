#include "Base.hpp"

int main(int argc,char** argv){
    float in=readInparm(argv[1]);
    Self sarr=readSelfparm(argv[1]);
    float weight=1.0;
    Self stmp,star;
    stmp = sarr;
    star = NULL;
    while(stmp){
        if(strcmp(stmp->cellname,argv[1])==0){
            weight=stmp->factor;
            stmp->factor*=0.8;
            if(stmp->prev){
                stmp->prev->next=stmp->next;
            }else{
                sarr = NULL;
            }
            if(stmp->next) stmp->next->prev=stmp->prev;
            star=stmp;
        }
        stmp=stmp->next;
    }
    if(star==NULL){
        star=(Self)malloc(sizeof(self));
        star->factor=1.0;
        star->cellname=argv[1];
    }
    star->prev=NULL;
    star->next=sarr;
    if(sarr) sarr->prev=star;
    prtSelfparm(star,argv[2]);
    //freeSelf(star);
}