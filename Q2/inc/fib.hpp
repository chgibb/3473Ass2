#pragma once

/**
 * @brief 
 * 
 * Generates the nth Fibonacci number.
 * From answer by Dzmitry Huba https://stackoverflow.com/questions/1518726/recursive-fibonacci
 * 
 * @param n
 * 
 * @return int
 */
int getFib(int n)
{
    int a = 1;
    int b = 1;
    for(int i = 3; i <= n; i++)
    {
        int c = a + b;
        a = b;
        b = c;
    }           
    return b;
}

/**
 * @brief 
 * 
 * Places the Fibonacci series up to n(inclusive) into con
 * 
 * @param n
 * @param Container* con
 * 
 * @return template <class Container> void
 */
template <class Container>
void getFibSeries(int n,Container*con)
{
    for(int i = 0; i != n; ++i)
    {
        con->push_back(::getFib(i));
    }
}