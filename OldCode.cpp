#include <string>
#include <iostream>
#include <vector>
#include <sstream>  
#include <numeric>
#include <iterator>
#include <algorithm>
#include <map>
std::vector<int> Fibonacci(int n)
{
    std::vector<int> output(n);
    if (n==1)
    {
        output[0]=1;
        return output;

    }
    else if (n==2)
    {
        output[1]=1;
        return output;
    }
    output[0]=1;
    output[1]=1;
    std::generate(output.begin()+2, output.end(), [a = 1,b = 1] () mutable { 

        a+=b;
        b=a-b;
        return a;});
    return output;

}

void ShiftRange(std::vector<int> &v, int left, int right)
{
    std::vector<int> inrange(10);
    std::vector<int> outrange(10);
    std::transform(v.begin(), v.end(),inrange.begin(), [left,right](int a){return a >=left && a <=right;});
    std::transform(v.begin(), v.end(),outrange.begin(), [left,right](int a){return a < left && a > right;});
    std::sort(outrange.begin(),outrange.end(),std::greater<int>());
    std::sort(inrange.begin(),inrange.end(),std::greater<int>());
    inrange.insert(inrange.end(), outrange.begin(), outrange.end());
    v=inrange;

}

int main()
{
    std::vector<int> test = Fibonacci(15);
     for (auto iv: test) {
        std::cout << iv << " ";
    }
    std::vector<int> test_case = {13, 22, 4, 5, 3, 11, 16, 25, 7};
    ShiftRange(test_case,10,20);
        for (auto iv1: test_case) {
        std::cout << iv1 << " " << std::endl;
    }
}