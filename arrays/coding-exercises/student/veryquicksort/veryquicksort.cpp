#include "veryquicksort.h"
#include <iostream>

void veryquicksort(int* ns, unsigned size)
{
    if(size == 0 || size == 1){
        return;
    }
    int* digits = new int[10];
    bool* found = new bool[10];
    for(int i=0;i<10;++i){
        digits[i] = 0;
        found[i] = false;
    }
    for(int i=0;i<size;++i){
        found[(ns[i]%10)] = true;
        digits[(ns[i])%10] += 1;
    }
    int index = 0;
    for(int i=0;i<10;++i){
        if(found[i]){
            for(int j=0;j<digits[i];++j){
                ns[index] = i;
                ++index;
            }
        }
    }
    delete[] digits;
    delete[] found;
}