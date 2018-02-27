#include "range.h"


int* range(int from, int to)
{
    int size = to - from + 1;
    int* range = new int[size];
    for (int i=0; i<size; ++i){
        range[i] = from + i;
    }
    return range;
}
