#pragma once
#include <future>
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
    return 1;
}

/**
 * @brief 
 * 
 * Returns a packaged_task representing a parallelized version of getAverage
 * 
 * @param 
 * 
 * @return std::packaged_task<T(std::vector<T>&)>
 */
template <class T>
std::packaged_task<T(std::vector<T>&)> getAverageParallel()
{
    return std::packaged_task<T(std::vector<T>&)>(getAverage<T>);
}
