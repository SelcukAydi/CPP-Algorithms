#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include <cmath>

// My solution.
//
std::vector<int> solution(const std::vector<int>& A)
{
    int n = A.size();
    std::vector<int> ans(n, 0);
    std::vector<int> numbers(n * 2 + 2, 0);
    
    // Accumulate the items as index in vector.
    //
    for(int i = 0; i < n; ++i)
    {
        ++numbers[A[i]];
    }

    for(int i = 0; i < n; ++i)
    {
        int j = 1;

        // Find all the divisors of A[i].
        //
        while(j * j <= A[i])
        {
            // This means j is one of the divisor.
            //
            if(A[i] % j == 0)
            {
                if(numbers[j])
                    ans[i] += A[i] != j ? numbers[j] : numbers[j] - 1;

                // Now find the other divisor.
                //
                int tmp = A[i] / j;
                
                if(tmp == j)
                {
                    ++j;
                    continue;
                }

                if(A[i] == tmp && numbers[tmp])
                {
                    ans[i] += numbers[tmp] - 1;
                }
                else if(numbers[tmp])
                {
                    ans[i] += A[i] != tmp ? numbers[tmp] : numbers[tmp] - 1;
                }
            }

            ++j;
        }

        // Now find the nondivisors.
        //
        ans[i] = n - (ans[i] + 1);
    }

    return ans;
}

// Solution on web.
//
std::vector<int> solution1(std::vector<int> &A)
{
    std::vector<int> dCount = std::vector<int>(A.size() * 2 + 2, -1);
    std::vector<int> nCount = std::vector<int>(A.size() * 2 + 2, 0);
    for (int i = 0; i < A.size(); i++)
        nCount[A[i]]++;
    std::vector<int> ans = std::vector<int>(A.size());
    for (int i = 0; i < A.size(); i++)
    {
        if (dCount[A[i]] >= 0)
        {
            ans[i] = A.size() - dCount[A[i]];
            continue;
        }
        dCount[A[i]] = 0;
        for (int j = 1; j <= sqrt(A[i]); j++)
        {
            if (A[i] % j == 0)
            {
                dCount[A[i]] += nCount[j];
                if (j != A[i] / j)
                    dCount[A[i]] += nCount[A[i] / j];
            }
        }
        ans[i] = A.size() - dCount[A[i]];
    }
    return ans;
}

// Enable this to test performance difference between two solutions.
//
// #define NORMAL 1

int main(int argc, char const *argv[])
{
    #ifdef NORMAL
    std::vector<int> v1 = { 3,1,2,3,6 };
    auto ans1 = solution(v1);
    for(const auto& a : ans1)
    {
        std::cout << a << ' ';
    }
    puts("");

    std::vector<int> v2 = { 2,2, };
    auto ans2 = solution(v2);
    for(const auto& a : ans2)
    {
        std::cout << a << ' ';
    }
    puts("");

    std::vector<int> v3 = { 4, 4 };
    auto ans3 = solution(v3);
    for(const auto& a : ans3)
    {
        std::cout << a << ' ';
    }
    puts("");

    #else
    std::vector<std::chrono::_V2::steady_clock::rep> times;

    for (int i = 0; i < 100; ++i)
    {
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

        std::vector<int> v1 = {3, 1, 2, 3, 6};
        auto ans1 = solution1(v1);
        // for (const auto &a : ans1)
        // {
        //     std::cout << a << ' ';
        // }
        // puts("");

        std::vector<int> v2 = {
            2,
            2,
        };
        auto ans2 = solution1(v2);
        // for (const auto &a : ans2)
        // {
        //     std::cout << a << ' ';
        // }
        // puts("");

        std::vector<int> v3 = {4, 4};
        auto ans3 = solution1(v3);
        // for (const auto &a : ans3)
        // {
        //     std::cout << a << ' ';
        // }
        // puts("");

        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        times.push_back(elapsed);
    }

    auto result = std::accumulate(times.begin(), times.end(), 0.0) / times.size();

    std::cout << "time elapsed: " << result << "[ns]\n";

    #endif
    
    return 0;
}
