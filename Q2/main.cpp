#include <iostream>
#include <vector>

#include "inc/fib.hpp"
#include "../inc/parallelize.hpp"

/**
 * @brief 
 * 
 * Main entry
 * 
 * @param argc
 * @param char*argv[]
 * 
 * @return int
 */
int main(int argc,char*argv[])
{
    if(argc <= 1)
    {
        std::cout<<"Insufficient arguments\n";
        return 1;
    }
    else if(argc > 2)
    {
        std::cout<<"Too many arguments\n";
        return 1;
    }

    return 0;
}