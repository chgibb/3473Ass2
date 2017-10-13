#include <iostream>
#include <vector>
#include <future>
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
    
    std::vector<int>* fibSeries = new std::vector<int>();

    std::future<void> fibSeriesFuture = ::launchParallel<void,int,std::vector<int>*>(
        &::getFibSeries<std::vector<int>>,
        std::atoi(argv[1]),
        fibSeries
    );
    fibSeriesFuture.get();

    for(auto it = fibSeries->begin(); it != fibSeries->end(); ++it)
    {
        std::cout<<" "<<*it;
    }
    std::cout<<std::endl;

    return 0;
}