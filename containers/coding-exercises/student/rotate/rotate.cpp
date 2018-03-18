#include "rotate.h"


void rotate(std::vector<int>* ns, int delta)
{
    if((*ns).size() != 0 && delta%(*ns).size() != 0){
        auto ms = *ns;
        if(delta < 0){
            delta = ms.size() - delta%ms.size();
        }
        for(int i=0;i<(*ns).size();++i){
            (*ns)[(i+delta)%ms.size()] = ms[i];
        }
    }
}