#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

int solution(const std::vector<std::vector<int>>& arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int begin = INT_MAX;
    int end = INT_MIN;

    // Find the min item.
    //
    for(int i = 0; i < n; ++i)
    {
        begin = std::min(begin, arr[i][0]);
    }

    // Find the max item.
    //
    for(int i = 0; i < n; ++i)
    {
        end = std::max(end, arr[i][m - 1]);
    }

    int k = (n * m) / 2;

    // Binary search between the [min, max] range.
    //
    while(begin < end)
    {
        int leftCounter = 0;

        // This is middle currently.
        //
        int candidate = (begin + end) / 2;

        // Find the number of items less than candidate.
        //
        for(int i = 0; i < n; ++i)
        {
            leftCounter += std::upper_bound(arr[i].begin(), arr[i].end(), candidate) - arr[i].begin();
        }

        if(leftCounter <= k)
        {
            // Since the candidate is also counted by upper_bound method
            // we actaully test candidate + 1 -th item. Suppose you have
            // A = { 1,2,3,4,5 }. Here 3 is the median. The upper_bound
            // will return 3 if the candidate is 3 cause 3 <= 3 is true.
            // Upper bound will return the first item bigger than candidate.
            // So our answer potantial answer for this iteration is candidate + 1.
            // Moreover, this solution works for A = { 2,2,2,2,2,3,3,3,3 } and etc... as well.
            //
            begin = candidate + 1;
        }
        else
        {
            end = candidate;
        }
    }

    return begin;
}

int main(int argc, char const *argv[])
{

    std::vector<std::vector<int>> arr1 = { {1,3,5}, {2,6,9}, {3,6,9} };
    std::vector<std::vector<int>> arr2 = { {1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3} };
    std::vector<std::vector<int>> arr3 = { {2,2,2,2,2,2,2} };

    std::cout << solution(arr3) << '\n';
    
    return 0;
}
