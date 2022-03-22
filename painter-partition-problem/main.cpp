#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <numeric>

#include <chrono>

bool f(int val, int sum, int A, std::vector<int> C)
{
    int i=0, workDone=0, paintersUsed=0;
    
    //this function returns if it is possible to finish the job with contiguous partitions,
    //with A painters, if each painter paints a maximum of "val" units of board.
    
    while(paintersUsed<A)
    {
        int temp=0,flag=1;
        while(i<C.size() && temp+C[i]<=val)
        {
            temp+=C[i++];
            flag=0;
        }
        
        if(flag)
            return false; //if one of the boards is too big for a single painter, with "val" max capacity
        else
        {
            workDone+=temp;
            paintersUsed++;
        }
        
        if(workDone==sum)
            return true;
    }
    
    return false; //if even A painters couldn't finish all the boards with this capacity
}


int solution1(int A, int B, std::vector<int> &C) {
    
    int sum = 0;
    for(auto x:C)
        sum+=x;
        
    //For valid values, we store the value as answer, and check for a lower value.
    //If found valid for a lower value, we replace that as answer.
    
    //For invalid values, we check for higher values until we find the next valid one.
    
    //Search ends when we find the last invalid value

    int answer=0;
    
    for(int b = sum; b>=1; b/=2)
        while(!f(answer+b, sum, A, C)) answer+=b;

    return (((long long int)answer+1)%10000003 * (B%10000003))%10000003;
    //answer+1 since we ended search at last invalid value
}

bool check(int A, int workToDone, int totalWork, const std::vector<int>& C)
{
    int isValid = true;
    int workDone = 0;
    int n = C.size();
    int i = 0;

    for(int p = 0; p < A && i < n; ++p)
    {
        int currentWorkDone = 0;

        while(i < n && currentWorkDone + C[i] <= workToDone)
        {
            currentWorkDone += C[i++];
        }

        if(currentWorkDone == 0)
        {
            isValid = false;
            break;
        }

        workDone += currentWorkDone;
    }

    if(workDone < totalWork)
    {
        isValid = false;
    }

    return isValid;
}

int solution(int A, int B, const std::vector<int>& C)
{
    long long ans = 0;
    int begin = 1;
    int end = std::accumulate(C.begin(), C.end(), 0);
    int totalWork = end;

    while(begin <= end)
    {
        int mid = (begin + end) / 2;

        if(check(A, mid, totalWork, C))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            begin = mid + 1;
        }
    }

    ans *= B;
    ans %= 10000003L;
    return ans;
}

int main(int argc, char const *argv[])
{
    std::vector<std::chrono::_V2::steady_clock::rep> times;

    for (int i = 0; i < 100; ++i)
    {
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

        std::vector<int> v1 = {1, 8, 11, 3};
        //std::cout << solution1(10, 1, v1) << '\n';
        solution1(10, 1, v1);

        std::vector<int> v2 = {658, 786, 531, 47, 169, 397, 914};
        //std::cout << solution1(5, 10, v2) << '\n';
        solution1(5, 10, v2);

        std::vector<int> v3 = {640, 435, 647, 352, 8, 90, 960, 329, 859};
        //std::cout << solution1(3, 10, v3) << '\n';
        solution1(3, 10, v3);

        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        times.push_back(elapsed);
    }

    auto result = std::accumulate(times.begin(), times.end(), 0.0) / times.size();

    std::cout << "time elapsed: " << result << "[ns]\n";

    return 0;
}
