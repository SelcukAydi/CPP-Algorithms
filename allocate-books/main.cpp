#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


bool check(std::vector<int>& arr, int limit, int B)
{
    int blocks = 0;
    int sum = 0;
    int n = arr.size();

    for(int i = 0; i < n; ++i)
    {
        if(sum + arr[i] > limit)
        {
            ++blocks;
            sum = arr[i];
            if(sum > limit) return false;
            continue;
        }

        sum += arr[i];
    }

    if(blocks < B) return true;
    return false;
}

int solution(std::vector<int>& A, int B)
{
    int ans = -1;
    int n = A.size();
    int begin = *(std::min_element(A.begin(), A.end()));
    int end = std::accumulate(A.begin(), A.end(), 0);

    if(B > n) return ans;

    while(begin <= end)
    {
        int mid = (begin + end) >> 1;

        if(check(A, mid, B))
        {
            ans = mid;
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
    
    std::vector<int> v1 = { 12, 34, 67, 90 };
    std::vector<int> v2 = { 73, 58, 30, 72, 44, 78, 23, 9 };
    std::vector<int> v3 = { 97, 26, 12, 67, 10, 33, 79, 49, 79, 21, 67, 72, 93, 36, 85, 45, 28, 91, 94, 57, 1, 53, 8, 44, 68, 90, 24 };
    std::vector<int> v4 = { 31, 14, 19, 75 };

    std::cout << solution(v4, 12) << '\n';

    return 0;
}
