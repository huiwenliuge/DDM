#include "Base.hpp"

int main(int argc,char** argv){
    float in = readInparm(argv[1]);
    float out = in;
    prtOutparm(out,argv[2]);
    prtOutparm(0.0,argv[1]);
}