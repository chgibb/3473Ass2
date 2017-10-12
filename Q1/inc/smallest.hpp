#pragma once

/**
 * @brief 
 * 
 * Returns the smallest T in nums
 * 
 * @param template <class Container> nums
 * 
 * @return template <class T> T
 */
template <class T,class Container>
T getSmallest(Container nums)
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