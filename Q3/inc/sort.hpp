#pragma once
#include <algorithm>

template <class T,class Container>
void sortAscending(Container*con)
{
    std::sort(con->begin(),con->end(),[](T a,T b) -> bool {
        return a < b;
    });
}