#include <iostream>
#include <vector>
#include <cstdlib>

#include "inc/average.hpp"
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

    std::vector<int> nums;

    for(int i = 1; i != argc; ++i)
    {
        nums.push_back(std::atoi(argv[i]));
    }

    auto averageFuture = ::launchParallel<int,std::vector<int>&>(&::getAverage<int>,nums);

    std::cout<<"Average: "<<averageFuture.get()<<std::endl;
    return 0;
}