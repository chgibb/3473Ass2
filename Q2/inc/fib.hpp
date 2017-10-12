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
int fib(int n)
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