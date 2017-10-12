#include <iostream>
#include <vector>
#include <cstdlib>

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
    if(argc < 2)
    {
        std::cout<<"Insufficient arguments\n";
        return 1;
    }
    else if(argc > 2)
    {
        std::cout<<"Too many arguments\n";
        return 1;
    }
    
    std::vector<int> fibSeries;
    ::getFibSeries<std::vector<int>&>(std::atoi(argv[1]),fibSeries);
    for(auto it = fibSeries.begin(); it != fibSeries.end(); ++it)
    {
        std::cout<<" "<<*it;
    }
    std::cout<<std::endl;

    return 0;
}