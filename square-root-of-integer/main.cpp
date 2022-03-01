#include <iostream>
#include <math.h>

int solution(int A)
{
    uint64_t ans;
    uint64_t begin = 1;
    uint64_t end = A;

    while(begin <= end)
    {
        uint64_t mid = (begin + end) / 2;
        uint64_t tmp = mid * mid;

        if(tmp <= A)
        {
            begin = mid + 1;
            ans = mid;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    std::cout << solution(2147483647) << '\n';

    return 0;
}
