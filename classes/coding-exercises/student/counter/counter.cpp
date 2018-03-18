#include "counter.h"

Counter::Counter(){
    val = 0;
}
unsigned int Counter::getValue() const{
    return val;
}
void Counter::increment(){
    val += 1;
}
void Counter::reset(){
    val = 0;
}
void Counter::setValue(unsigned int value){
    val = value;
}
// TODO
