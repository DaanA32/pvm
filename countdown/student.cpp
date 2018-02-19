#include <iostream>
void countdown(int from)
{
    while(from >= 1){
        std::cout << from-- << std::endl;
    }
}