#include <iostream>
#include <vector>

bool check(const std::vector<int> &A, const std::vector<int> &B, const std::vector<int> &C, int mid)
{
    bool allNailled = true;

    std::vector<int> presums(2 * C.size() + 1, 0);

    // Mark nailled positions.
    //
    for(int i = 0; i < mid + 1; ++i)
    {
        presums[C[i]] = 1;
    }

    // Accumulate the prefix sums.
    //
    for(int i = 1; i < presums.size(); ++i)
    {
        presums[i] += presums[i -1];
    }

    // Check all placks(ranges) if they are all nailled.
    //
    for(int i = 0; i < A.size() && allNailled; ++i)
    {
        allNailled = presums[B[i]] - presums[A[i] - 1] > 0;
    }

    return allNailled;
}

int solution(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C)
{
    int ans = -1;
    int begin = 0;
    int end = C.size() - 1;

    while(begin <= end)
    {
        int mid = (begin + end) / 2;

        if(check(A, B, C, mid))
        {
            ans = mid + 1;
            end = mid - 1;
        }
        else
        {
            begin = mid + 1;
        }
    }

    return ans;
}


int main(int argc, char const *argv[])
{
    std::vector<int> A = { 1,4,5,8 };
    std::vector<int> B = { 4,5,9,10 };
    std::vector<int> C = { 4,6,7,10,2 };
    
    std::cout << solution(A, B, C) << '\n';

    
    return 0;
}
