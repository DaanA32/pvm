#include "nth.h"

int& nth(std::vector<int>& ns, int i){
    int index = (i)%int(ns.size());
    index += int(ns.size());
    index = index %int(ns.size());
    return ns[index];
}


int nth(const std::vector<int>& ns, int i){
    int index = (i)%int(ns.size());
    index += int(ns.size());
    index = index %int(ns.size());
    return ns[index];
}