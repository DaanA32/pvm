#include "split.h"


void split(int* ns, unsigned size, int** odds, unsigned* n_odds, int** evens, unsigned* n_evens)
{
    *n_odds = 0;
    *n_evens = 0;
    if(ns != nullptr){
        for(int i=0;i<size;++i){
            ns[i]%2==0? (*n_evens)++ : (*n_odds)++;
        }
        *odds = new int[*n_odds];
        *evens = new int[*n_evens];
        unsigned j = 0;
        unsigned k = 0;
        for(int i=0;i<size;++i){
            ns[i]%2==0 ? (*evens)[j++] = ns[i] : (*odds)[k++] = ns[i];
        }
    }else{
        *odds = new int[0];
        *evens = new int[0];
    }
}
