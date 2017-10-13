#pragma once
#include <algorithm>

/**
 * @brief 
 * 
 * Sorts con in ascending order. Container is the container type of con
 * and T is the type contained
 * 
 * @param Container*&con
 * 
 * @return template <class T,class Container> void
 */
template <class T,class Container>
void sortAscending(Container*&con)
{
    std::sort(con->begin(),con->end(),[](T a,T b) -> bool {
        return a < b;
    });
}