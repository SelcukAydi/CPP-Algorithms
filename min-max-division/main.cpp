#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int check(const std::vector<int>& arr, int k, int midCandidateLargeSum)
{
    uint64_t sum = 0;
    uint64_t blocks = 1;

    for(int i = 0; i < arr.size(); ++i)
    {
        sum += arr[i];

        if(sum > midCandidateLargeSum)
        {
            ++blocks;
            sum = arr[i];
        }
    }

    return blocks;
}

int solution(const std::vector<int>& arr, int k)
{
    int maxLarge = *(std::max_element(arr.cbegin(), arr.cend()));
    int total = std::accumulate(arr.cbegin(), arr.cend(), 0);
    int ans = total;

    while(maxLarge <= total)
    {
        int mid = (maxLarge + total) / 2;

        if(check(arr, k, mid) <= k)
        {
            total = mid - 1;
            ans = mid;
        }
        else
        {
            maxLarge = mid + 1;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    std::vector<int> v1 = { 2,1,5,1,2,2,2 };

    std::cout << solution(v1, 3) << '\n';
    
    return 0;
}
