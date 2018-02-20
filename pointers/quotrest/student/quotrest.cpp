#include "quotrest.h"

void quotrest(int x, int y, int* q, int* r){
    if(y != 0){
        *q = x/y;
        *r = x%y;
    }
}