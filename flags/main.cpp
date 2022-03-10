#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

int solution(const std::vector<int>& A)
{
    int ans = 0;
    int n = A.size();

    std::vector<int> peaks;

    // Collect the peaks.
    //
    for(int i = 1; i < n - 1; ++i)
    {
        if(A[i] > A[i + 1] && A[i - 1] < A[i]) peaks.push_back(i);
    }

    if(peaks.empty()) return 0;

    // We may have maximum sqrt(n) number of flags.
    // This is because of the following:
    // Let's assume we have k flags at most.
    // Then we have maximum k-1 distance between
    // the current flag and the next one.
    // As total we will have k.(k-1)+k number of items
    // in the full array. This yields k^2 peaks needed.
    //
    for(int flags = (int)std::ceil(std::sqrt(n)); flags >= 1; --flags)
    {
        int lastFlag = 0;
        bool found = true;

        auto itr = std::lower_bound(peaks.begin(), peaks.end(), lastFlag);

        for(int i = 0; i < flags; ++i)
        {
            if(itr == peaks.end())
            {
                found = false;
                break;
            }

            lastFlag = *itr;

            itr = std::lower_bound(peaks.begin() + (itr - peaks.begin()), peaks.end(), lastFlag + flags);
        }

        if(found) return flags;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    std::vector<int> v1 = { 1,5,3,4,3,4,1,2,3,4,6,2 };

    std::cout << solution(v1) << '\n';
    
    return 0;
}
