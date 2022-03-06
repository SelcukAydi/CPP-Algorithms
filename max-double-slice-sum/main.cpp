#include <iostream>
#include <vector>
#include <algorithm>

int solution(const std::vector<int>& A)
{
    int n  = A.size();
    int ans = 0;
    
    std::vector<int> leftSum(A.size(), 0);
    std::vector<int> rightSum(A.size(), 0);

    // Start from the left and to find the sub-array with max sum.
    //
    for(int i = 1; i < n - 1; ++i)
    {
        leftSum[i] = std::max(0, leftSum[i - 1] + A[i]);
    }

    // Start from the right and to find the sub-array with max sum.
    //
    for(int i = n - 2; i > 0; --i)
    {
        rightSum[i] = std::max(0, rightSum[i + 1] + A[i]);
    }

    // leftSum[i]   = A[1] + A[2] + A[3] + ... + A[i - 1]
    // rightSum[i]  = A[i + 1] + A[i + 2] + A[i + 3] + ... + A[n - 2]
    // We can now find the maximum sum easily.
    //
    for(int i = 1; i < n - 1; ++i)
    {
        ans = std::max(ans, leftSum[i - 1] + rightSum[i + 1]);
    }

    return ans;
}

int main(int argc, char const *argv[])
{

    std::vector<int> v1 = { 3,2,6,-1,4,5,-1,2 };

    std::cout << solution(v1) << '\n';
    
    return 0;
}
