#pragma once
#include <future>
#include <vector>

template <class T>
T getAverage(std::vector<T>&nums)
{
    return 1;
}

template <class T>
std::packaged_task<T(std::vector<T>&)> getAverageParallel()
{
    return std::packaged_task<T(std::vector<T>&)>(getAverage<T>);
}
