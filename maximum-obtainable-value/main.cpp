#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int solve(int N)
{
    int currentMax;

    if(N > 0)
    {
        currentMax = INT_MIN;
    }
    else
    {
        currentMax = INT_MAX;
    }

    int tmpN = N;
    std::vector<int> acc;
    int counter = 0;

    N = std::abs(N);

    int i = N;
    int counter5 = 0;
    do
    {
        int mod = i % 10;
        i /= 10;
        if (mod == 5)
            ++counter5;

    } while (i != 0);

    while (counter5 != 0)
    {
        int tmp = N % 10;
        N /= 10;
        if (tmp == 5)
        {
            if (std::max(counter, 0) != 0)
            {
                --counter;
                acc.push_back(5);
                continue;
            }

            int t = N;
            for (auto itr = acc.rbegin(); itr != acc.rend(); ++itr)
            {
                t *= 10;
                t += *itr;
            }

            if (tmpN < 0)
            {
                currentMax = std::min(currentMax, t);
            }
            else
            {
                currentMax = std::max(currentMax, t);
            }
            acc.clear();
            N = std::abs(tmpN);
            ++counter;
            --counter5;
        }
        else
        {
            acc.push_back(tmp);
        }
    }

    return tmpN > 0 ? currentMax : -currentMax;
}

int convertToNumber(const std::vector<int>& v, int dropIndex)
{
    int ans = 0;

    for(int i = v.size() - 1; i >= 0; --i)
    {
        if(i != dropIndex)
        {
            ans *= 10;
            ans += v[i];
        }
    }

    return ans;
}

int solve1(int N)
{
    std::vector<int> v;
    bool isPositive = N > 0;
    int ans = INT_MIN;
    N = std::abs(N);

    while(N != 0)
    {
        int digit = N % 10;
        N /= 10;
        v.push_back(digit);
    }

    for(int i = 0; i < v.size(); ++i)
    {
        if(v[i] == 5)
        {
            ans = isPositive ? std::max(ans, convertToNumber(v, i)) : std::max(ans, -convertToNumber(v, i));
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    std::cout << solve1(-159659) << '\n';

    return 0;
}
