#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <algorithm>

std::unordered_map<int, int> cache;

using namespace std;

vector<int> solution1(vector<int> &A, vector<int> &B) {
    size_t maxB = *std::max_element(B.begin(), B.end());
    size_t maxA = *std::max_element(A.begin(), A.end());
	
    vector<int> L(A.size(), 0);
    vector<size_t> fib(maxA + 2, 0);
    fib[1] = 1;
    maxB = 30;

    std::cout << "Mask is " << ((1 << maxB)-1) << '\n';
	
    for (size_t i = 2; i < maxA + 2; i++)
    {
        int tmp = (fib[i - 1] + fib[i - 2]);
        std::cout << "Fib " << i << " is " << tmp << '\n';
        tmp = tmp & ((1 << maxB)-1);
        std::cout << "After mask is " << tmp << '\n';
        fib[i] = tmp;
        
    }

    for (size_t i = 0; i < A.size(); i++) {
        size_t mask = (1 << B[i]) - 1;
        L[i] = fib[A[i] + 1] & mask;
        std::cout << "result for " << fib[A[i] + 1] << " is " << L[i] << '\n';
    }

    return L;
}


int fibonacci(int N)
{
    auto itr = cache.find(N);
    
    if(itr != cache.end())
    {
        return itr->second;
    }

    if(N <= 2)
    {
        cache.emplace(std::pair<int, int>(N, N));
        return N;
    }
    
    int tmp = fibonacci(N - 1) + fibonacci(N - 2);
    cache.emplace(std::pair<int, int>(N, tmp));

    return tmp;
}

constexpr double square5 = 2.236067977;

int fastFibonacci(int N)
{
    ++N;
    double ans = std::ceil((std::pow(1.61803, N) - std::pow(-0.61803, N)) / square5);
    return ans;
}

std::vector<int> solution(std::vector<int> &A, std::vector<int> &B)
{
    std::vector<int> ans;

    for(int i = 0; i < A.size(); ++i)
    {
        int ways = fibonacci(A[i]);
        ans.push_back(ways % (int)std::pow(2, B[i]));
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    std::vector<int> v1 = { 4,4,5,5,1,10 };
    std::vector<int> v2 = { 3,2,4,3,1,3 };
        
    auto ans = solution1(v1, v2);

    //std::cout << fibonacci(10) << '\n';

    // // for(int i = 0; i < ans.size(); ++i)
    // // {
    // //     std::cout << ans[i] << ' ';
    // // }

    // std::cout << fastFibonacci(4) << '\n';

    return 0;
}
