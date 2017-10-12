#include <iostream>
#include <vector>
#include <cstdlib>
#include <thread>
#include <functional>

#include "inc/average.hpp"

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
    
    std::future<int> averageFuture;
    {
        auto averageTask = getAverageParallel<int>();
        averageFuture = averageTask.get_future();
        std::thread(std::move(averageTask),std::ref(nums)).detach();
    }

    std::cout<<averageFuture.get();

    return 0;
}