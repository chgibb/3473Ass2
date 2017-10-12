#pragma once
#include <iterator>

/**
 * @brief 
 * 
 * Allocates and fills l with the first half of in and r with the latter half of in.
 * Based on answer by Xeo https://stackoverflow.com/questions/9811235/best-way-to-split-a-vector-into-two-smaller-arrays
 * 
 * @param Container*in
 * @param Container*l
 * @param Container*r
 * 
 * @return template <class Container> void
 */
template <class Container>
void split(Container*in,Container*l,Container*r)
{
    size_t middle = in->size()/2;

    l = new Container(in->begin(),in->begin() + middle);
    r = new Container(in->begin() + middle,in->end());
}