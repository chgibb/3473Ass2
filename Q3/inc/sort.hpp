#pragma once

/**
 * @brief 
 * Partition con.
 * Based on answer by tgmath https://stackoverflow.com/questions/22504837/how-to-implement-quick-sort-algorithm-in-c
 * @param Container*&con
 * @param int p
 * @param SizeType q
 * @return template <class T,class Container,class SizeType> SizeType 
 */
template <class T,class Container,class SizeType>
SizeType partition(Container*&con,int p,SizeType q)
{
    T x = con->at(p);
    SizeType i = p;
    int j;
    for(j = p + 1; j < q; ++j)
    {
        if(con->at(j) <= x)
        {
            i = i + 1;
            std::swap(con[i],con[j]);
        }
    }
    std::swap(con[i],con[p]);
    return i;
}

/**
 * @brief 
 * 
 * Sorts con in ascending order. Container is the container type of con
 * and T is the type contained.
 * Based on answer by tgmath https://stackoverflow.com/questions/22504837/how-to-implement-quick-sort-algorithm-in-c
 * 
 * @param Container*&con
 * @param int p
 * @param SizeType q
 * 
 * @return template <class T,class Container,class SizeType> void
 */
template <class T,class Container,class SizeType>
void quickSort(Container*&con,int p,SizeType q)
{
    SizeType r;
    if(p < q)
    {
        r = ::partition<T,Container,SizeType>(con,p,q);
        ::quickSort<T,Container,SizeType>(con,p,r);
        ::quickSort<T,Container,SizeType>(con,r + 1,q);
    }
}