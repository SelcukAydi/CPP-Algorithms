#include <iostream>
#include <vector>
#include <algorithm>

int solution(const std::vector<int>& A)
{
    int n = A.size();
    int ans = 0;

    std::vector<long> left(n, 0L);
    std::vector<long> right(n, 0L);

    for(long i = 0; i < n; ++i)
    {
        left[i] = i - A[i];
        right[i] = i + A[i];
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    for(int i = 0, j = 0; i < n; ++i)
    {
        while(j < n && left[j] <= right[i]) ++j;
        ans += j - i - 1;
        if(ans > 10000000) return -1;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    std::vector<int> v1 = { 1,5,2,1,4,0 };

    std::cout << solution(v1) << '\n';
    
    return 0;
}
