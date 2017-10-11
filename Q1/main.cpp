#include <iostream>
#include <vector>
#include <string>

int main(int argc,char*argv[])
{
    if(argc <= 1)
    {
        std::cout<<"Insufficient arguments\n";
        return 1;
    }
    std::vector<float> nums;
    for(int i = 1; i != argc; ++i)
    {
        nums.push_back(std::stof(std::string(argv[i])));
    }
    return 0;
}