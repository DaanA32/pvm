#include "swap.h"

void swap(int* p, int* q){
    int t = *p;
    *p = *q;
    *q = t;

}