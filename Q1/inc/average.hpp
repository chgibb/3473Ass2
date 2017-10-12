#pragma once
#include <vector>

/**
 * @brief 
 * 
 * Returns the average of all T in nums
 * 
 * @param std::vector<T>&nums
 * 
 * @return template <class T> T
 */
template <class T>
T getAverage(std::vector<T>&nums)
{
    T res = 0;
    auto end = nums.end();
    for(auto it = nums.begin(); it != end; ++it)
    {
        res += *it;
    }
    return res/nums.size();
}

