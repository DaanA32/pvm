#include "swap.h"

void swap(int& a, int& b){
    a^=b;
    b^=a;
    a^=b;
}