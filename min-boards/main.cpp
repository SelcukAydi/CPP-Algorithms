#include <iostream>
#include <vector>

int check(const std::vector<int>& arr, int k)
{
    int boards = 0;
    int last = -1;

    for(int i = 0; i < arr.size(); ++i)
    {
        if(arr[i] == 1 && last < i)
        {
            ++boards;
            i += k - 1;
        }
    }

    return boards;
}

int solution(const std::vector<int>& arr, int k)
{
    int n = arr.size();
    int ans = n;
    int begin = 0;
    int end = n;

    while(begin <= end)
    {
        int mid = (begin + end) / 2;

        if(check(arr, mid) <= k)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            begin = mid + 1;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    std::vector<int> arr = { 1,0,1,0,1,0,1,0 };

    std::cout << solution(arr, 2) << '\n';


    return 0;
}
