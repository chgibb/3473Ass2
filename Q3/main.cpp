#include <iostream>
#include <vector>
#include <future>
#include <cstdlib>

#include "inc/sort.hpp"
#include "inc/split.hpp"
#include "inc/merge.hpp"
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
    //read a list of numbers from the CLI into nums
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

    //pointers for the first and second halfs of nums, respectively
    std::vector<int>*firstHalf = nullptr;
    std::vector<int>*secondHalf = nullptr;

    ::split<std::vector<int>>(&nums,firstHalf,secondHalf);

    //launch threads to sort the first and second halfs, respectively
    std::future<void> firstHalfSortFuture = ::launchParallelRef<void,std::vector<int>*&>(
        &::sortAscending<int,std::vector<int>>,
        firstHalf
    );
    std::future<void> secondHalfSortFuture = ::launchParallelRef<void,std::vector<int>*&>(
        &::sortAscending<int,std::vector<int>>,
        secondHalf
    );

    //wait for both to finish
    firstHalfSortFuture.get();
    secondHalfSortFuture.get();

    //launch merging thread
    std::future<std::vector<int>> mergeFuture = ::launchParallelRef<std::vector<int>,std::vector<int>*&,std::vector<int>*&>(
        &::merge<std::vector<int>>,
        firstHalf,
        secondHalf
    );

    std::cout<<"First half, sorted: ";
    for(auto it = firstHalf->begin(); it != firstHalf->end(); ++it)
    {
        std::cout<<" "<<*it;
    }

    std::cout<<std::endl;

    std::cout<<"Second half, sorted: ";
    for(auto it = secondHalf->begin(); it != secondHalf->end(); ++it)
    {
        std::cout<<" "<<*it;
    }
    std::cout<<std::endl;

    //get merged results
    nums = mergeFuture.get();

    std::cout<<"Both merged: ";
    for(auto it = nums.begin(); it != nums.end(); ++it)
    {
        std::cout<<" "<<*it;
    }
    std::cout<<std::endl;

    return 0;
}