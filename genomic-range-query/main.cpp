#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> prefixSum(const std::string& arr)
{
    std::vector<std::vector<int>> sums(arr.size() + 1, { 0, 0, 0, 0 });

    for(int i = 1; i < sums.size(); ++i)
    {
        int ignore = 0;

        switch (arr.at(i - 1))
        {
        case 'A':
            sums[i][0] = sums[i - 1][0] + 1;
            ignore = 0;
            break;
        case 'C':
            sums[i][1] = sums[i - 1][1] + 1;
            ignore = 1;
            break;
        case 'G':
            sums[i][2] = sums[i - 1][2] + 1;
            ignore = 2;
            break;
        case 'T':
            sums[i][3] = sums[i - 1][3] + 1;
            ignore = 3;
            break;
        }

        for(int j = 0; j < 4; ++j)
        {
            if(ignore == j) continue;
            sums[i][j] = sums[i - 1][j];
        }
    }

    return sums;
}

std::vector<int> sliceSum(const std::vector<std::vector<int>>& sums, int a, int b)
{
    std::vector<int> ans(4, 0);

    for(int i = 0; i < 4; ++i)
    {
        ans[i] = sums[b + 1][i] - sums[a][i];
    }

    return ans;
}



std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q)
{
    std::vector<int> ans;
    auto sums = prefixSum(S);

    for(int i = 0; i < P.size(); ++i)
    {
        auto sum = sliceSum(sums, P[i], Q[i]);
        int minNucleotides = 5;
        int minIndex = 0;

        for(int j = 0; j < 4; ++j)
        {
            if(sum[j] == 0) continue;
            minIndex = j;
            break;
        }

        ans.push_back(minIndex + 1);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    // std::string s = "CAGCCTA";
    // std::vector<int> P = { 2,5,0 };
    // std::vector<int> Q = { 4,5,6 };

    std::string s = "C";
    std::vector<int> P = { 0 };
    std::vector<int> Q = { 0 };

    auto ans = solution(s, P, Q);
    
    return 0;
}
