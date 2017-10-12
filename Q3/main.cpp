#include <iostream>
#include <vector>
#include <cstdlib>

#include "inc/sort.hpp"
#include "inc/split.hpp"
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

    std::vector<int>*firstHalf = nullptr;
    std::vector<int>*secondHalf = nullptr;

    ::split<std::vector<int>>(&nums,firstHalf,secondHalf);

    for(auto it = firstHalf->begin(); it != firstHalf->end(); ++it)
    {
        std::cout<<" "<<*it;
    }
    std::cout<<std::endl;

    for(auto it = secondHalf->begin(); it != secondHalf->end(); ++it)
    {
        std::cout<<" "<<*it;
    }
    std::cout<<std::endl;

    return 0;
}