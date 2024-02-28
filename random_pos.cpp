#include "random_pos.h"

#include <random>  

int GetRandomStartPos(int min, int max)  
{  
    static std::random_device rand;  
    std::mt19937 gen(rand());  
    std::uniform_int_distribution<>dis(min, max);  
    int random_number = dis(gen);
    return random_number;
}  