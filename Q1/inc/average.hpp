#pragma once

/**
 * @brief 
 * 
 * Returns the average of all T in nums. Container is the container type of nums
 * and T is the contained type
 * 
 * @param template <class Container> nums
 * 
 * @return template <class T> T
 */
template <class T,class Container>
T getAverage(Container nums)
{
    T res = 0;
    auto end = nums.end();
    for(auto it = nums.begin(); it != end; ++it)
    {
        res += *it;
    }
    return res/nums.size();
}

