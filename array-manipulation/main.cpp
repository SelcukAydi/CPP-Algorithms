#include <iostream>
#include <vector>
#include <algorithm>

int64_t solution(int n, std::vector<std::vector<int>> queries)
{
    std::vector<long> arr(n + 1, 0);
    int64_t ans = 0;

    // Calculate the prefix sum for each interval.
    // The start index is sum and end + 1 is negative sum.
    // This way we ensure that we added sum once for the interval (start, end).
    //
    for(int i = 0; i < queries.size(); ++i)
    {
        arr[queries[i][0]] += queries[i][2];

        if(queries[i][1] + 1 < n + 1) arr[queries[i][1] + 1] -= queries[i][2];
    }

    int64_t sum = 0;

    // Find the maximum using prefix sum.
    //
    for(int i = 1; i < n + 1; ++i)
    {
        sum += arr[i];
        ans = std::max(ans, sum);
    }
    
    return ans;
}

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> v1 = { { 1,5,3 }, { 4,8,7 }, { 6,9,1 } }; // n = 10 //
    std::vector<std::vector<int>> v2 = { { 1,2,100 }, { 2,5,100 }, { 3,4,100 } }; // n = 5 //
    std::vector<std::vector<int>> v3 = { { 2,6,8 }, { 3,5,7 }, { 1,8,1 }, { 5,9,15 } }; // n = 10 //

    std::cout << solution(10, v3) << '\n';

    return 0;
}
