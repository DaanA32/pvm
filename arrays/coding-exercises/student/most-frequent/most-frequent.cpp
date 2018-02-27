#include "most-frequent.h"
#include <limits>


int most_frequent(int* ns, unsigned size)
{
    if(size == 1 || size == 2){
        return ns[0];
    }
    if(ns != nullptr){
        int* numbers = new int[size];
        int* count = new int[size];
        int index = 0;
        for(int i=0;i<size;++i){
            bool in_numbers = false;
            int k = 0;
            for(int j=0;j<index;++j){
                if(numbers[j] == ns[i]){
                    k = j;
                    in_numbers = true;
                    break;
                }
            }
            if(in_numbers){
                ++count[k];
            }else{
                numbers[index] = ns[i];
                count[index] = 1;
                ++index;
            }
        }
        int max_index = 0;
        for(int i=0;i<index;++i){
            if(count[i] > count[max_index]){
                max_index = i;
            }
        }
        int most = numbers[max_index];
        delete[] numbers;
        delete[] count;
        return most;
    }
}
