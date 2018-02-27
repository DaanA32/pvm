#include "lone-wolf.h"
#include <iostream>

int lone_wolf(int* ns, unsigned size)
{
    if(ns != nullptr){
        bool* has_partner = new bool[size];

        for(int i=0;i<size;++i){
            has_partner[i] = false;
        }
        for(int i=0;i<size;++i){
            if(!has_partner[i]){
                for(int j=0;j<size;j++){
                    if(i != j && !has_partner[j] && ns[i] == ns[j]){
                        has_partner[i] = true;
                        has_partner[j] = true;
                        break;
                    }
                }
            }
        }
        for(int i=0;i<size;++i){
            if(!has_partner[i]){
                return ns[i];
            }
        }
        return -1;
    }
}