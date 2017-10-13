#include <iostream>
#include <vector>
#include <future>
#include <cstdlib>

#include "inc/average.hpp"
#include "inc/smallest.hpp"
#include "inc/largest.hpp"
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

    std::future<int> averageFuture = ::launchParallelRef<int,std::vector<int>&>(
        &::getAverage<int,std::vector<int>&>,
        nums
    );
    std::future<int>  largestFuture = ::launchParallelRef<int,std::vector<int>&>(
        &::getLargest<int,std::vector<int>&>,
        nums
    );
    std::future<int>  smallestFuture = ::launchParallelRef<int,std::vector<int>&>(
        &::getSmallest<int,std::vector<int>&>,
        nums
    );

    std::cout<<"Average: "<<averageFuture.get()<<std::endl;
    std::cout<<"Largest: "<<largestFuture.get()<<std::endl;
    std::cout<<"Smallest: "<<smallestFuture.get()<<std::endl;
    return 0;
}