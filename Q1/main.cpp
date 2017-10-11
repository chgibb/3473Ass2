#include <iostream>
#include <vector>
#include <cstdlib>

int main(int argc,char*argv[])
{
    if(argc <= 1)
    {
        std::cout<<"Insufficient arguments\n";
        return 1;
    }
    std::vector<int> nums;
    for(int i = 1; i != argc; ++i)
    {
        nums.push_back(std::atoi(argv[i]));
    }
    return 0;
}