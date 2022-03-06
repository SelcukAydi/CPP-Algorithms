#include <iostream>
#include <vector>
#include <algorithm>

int solution(const std::vector<int>& arr)
{
    int currentMax = arr[0];
    int ans = arr[0];

    for(int i = 1; i < arr.size(); ++i)
    {
        currentMax = std::max(arr[i], currentMax + arr[i]);
        ans = std::max(currentMax, ans);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    std::vector<int> v1 = { 5, -7, 3, 5, -2, 4, -1 };

    std::cout << solution(v1) << '\n';
    
    return 0;
}
