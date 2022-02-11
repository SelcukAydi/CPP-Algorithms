#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> prefixSum(const std::vector<int>& arr)
{
    std::vector<int> prefixSum(arr.size() + 1, 0);

    for(int i = 1; i < prefixSum.size(); ++i)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }

    return prefixSum;
}

int sliceSum(const std::vector<int>& sums, int a, int b)
{
    return sums[b + 1] - sums[a];
}

int solution(const std::vector<int>& arr, int k, int m)
{
    int n = arr.size();
    int ans = 0;
    auto sums = prefixSum(arr);

    // First left then right.
    //
    for(int i = 0; i < std::min(m, k) + 1; ++i)
    {
        int leftPosition = k - i;
        int rightPosition = std::max(k, std::min(k + m - 2 * i, n - 1));
        ans = std::max(ans, sliceSum(sums, leftPosition, rightPosition));
    }

    // First right then left.
    //
    for(int i = 0; i < std::min(k + m + 1, n - k); ++i)
    {
        int rightPosition = k + i;
        int leftPosition = std::max(0, std::min(k, k - (m - 2 * i)));
        ans = std::max(ans, sliceSum(sums, leftPosition, rightPosition));
    }

    return ans;
}

int main(int argc, char const *argv[])
{   
    std::vector<int> v = { 2,3,7,5,1,3,9 };

    std::cout << solution(v, 4, 6) << '\n';

    return 0;
}
