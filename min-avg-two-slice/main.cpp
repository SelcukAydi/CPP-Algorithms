#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

std::vector<int> prefixSum(const std::vector<int> &arr)
{
    std::vector<int> prefixSum(arr.size() + 1, 0);

    for (int i = 1; i < prefixSum.size(); ++i)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }

    return prefixSum;
}

int sliceSum(const std::vector<int> &sums, int a, int b)
{
    return sums[b + 1] - sums[a];
}

int solution(const std::vector<int> &arr)
{
    int n = arr.size();
    auto sums = prefixSum(arr);
    float ans = sliceSum(sums, 0, 1) / 2;
    int minStart = 0;

    for (int p = 1; p < n; ++p)
    {
        for (int q = 0; q < n - p; ++q)
        {
            float avg = sliceSum(sums, q, q + p) / (float)(p + 1);

            if (ans > avg)
            {
                ans = avg;
                minStart = q;
            }
        }
    }

    return minStart;
}

int solution1(const std::vector<int> &arr)
{
    int n = arr.size();
    auto sums = prefixSum(arr);
    float currentMin = 100.f;
    int ans = 0;

    int l = 0;

    for(int r = 2; r < n; ++r)
    {
        float avg1 = sliceSum(sums, l, l + 1) / 2.0f;
        float avg2 = sliceSum(sums, l + 1, r) / 2.0f;
        float avg3 = sliceSum(sums, l, r) / 3.0f;

        if( currentMin > avg1 )
        {
            currentMin = avg1;
            ans = l;
        }
        
        if( currentMin > avg2 )
        {
            currentMin = avg2;
            ans = l + 1;
        }

        if( currentMin > avg3 )
        {
            currentMin = avg3;
            ans = l;
        }

        ++l;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    std::vector<int> v1 = { -3, -5, -8, -4, -10 };
    std::vector<int> v2 = { 4,2,2,5,1,5,8 };
    std::cout << solution1(v1) << '\n';

    return 0;
}
