#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<int> solution(const std::vector<int>& A, const std::vector<int>& B)
{
    int maxA = *std::max_element(A.begin(), A.end());

    std::vector<int> ans(A.size(), 0);
    std::vector<int> fibonaccies(maxA + 2, 0);

    fibonaccies[1] = 1;

    // Calculate the fibonacci series. Note that
    // we get modulo of each item in the fibonacci series.
    // This way prevents storing really big numbers.
    //
    for(int i = 2; i < maxA + 2; ++i)
    {
        fibonaccies[i] = fibonaccies[i - 1] + fibonaccies[i - 2];
        fibonaccies[i] = fibonaccies[i] & ((1 << 30) - 1);
    }

    // Now calculate the fibonacci of each item in the vector A.
    // Also calculate the modulo of each result with B.
    //
    for(int i = 0; i < A.size(); ++i)
    {
        ans[i] = fibonaccies[A[i] + 1] & ((1 << B[i]) - 1);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    std::vector<int> A = { 4,4,5,5,1,10 };
    std::vector<int> B = { 3,2,4,3,1,3 };
        
    auto ans = solution(A, B);

    for(int i = 0; i < ans.size(); ++i)
    {
        std::cout << ans[i] << ' ';
    }

    return 0;
}
