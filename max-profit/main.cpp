#include <iostream>
#include <vector>
#include <algorithm>

int solution(const std::vector<int>& arr)
{
    int ans = 0;
    int prevProfit = 0;
    int currentProfit = 0;

    for(int i = 1; i < arr.size(); ++i)
    {
        currentProfit = std::max(0, prevProfit + (arr[i] - arr[i - 1]));
        ans = std::max(currentProfit, ans);
        prevProfit = currentProfit;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    
    std::vector<int> v1 = { 3,5,6,1,7,2,8,4 };

    std::cout << solution(v1) << '\n';

    return 0;
}
