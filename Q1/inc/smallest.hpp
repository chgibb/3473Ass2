#pragma once
#include <vector>

/**
 * @brief 
 * 
 * Returns the smallest T in nums
 * 
 * @param std::vector<T>&nums
 * 
 * @return template <class T> T
 */
template <class T>
T getSmallest(std::vector<T>&nums)
{
    T res = nums[0];
    auto end = nums.end();
    for(auto it = nums.begin(); it != end; ++it)
    {
        if(*it < res)
            res = *it;
    }
    return res;
}