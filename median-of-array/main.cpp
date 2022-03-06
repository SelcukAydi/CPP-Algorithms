#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

double findMedian(const std::vector<int> &A, const std::vector<int> &B)
{
    int n = A.size() + B.size();
    int k = n / 2;
    int begin, end;
    int tmpEnd;
    int tmpBegin;

    if(A.empty())
    {
        begin = B[0];
        end = B[B.size() - 1];
        tmpEnd = end;
        tmpBegin = begin;
    }
    else if(B.empty())
    {
        begin = A[0];
        end = A[A.size() - 1];
        tmpEnd = end;
        tmpBegin = begin;
    }
    else
    {
        begin = std::min(A[0], B[0]);
        end = std::max(A[A.size() - 1], B[B.size() - 1]);
        tmpEnd = end;
        tmpBegin = begin;
    }

    if (n % 2 == 0) --k;

    int tmpMid = 0;

    while(begin < end)
    {
        int leftCounter = 0;
        int mid = (begin + end) / 2;
        if(tmpMid == mid) break;
        tmpMid = mid;

        if(!A.empty())
            leftCounter += std::upper_bound(A.begin(), A.end(), mid) - A.begin();
        
        if(!B.empty())
            leftCounter += std::upper_bound(B.begin(), B.end(), mid) - B.begin();

        if(leftCounter <= k)
        {
            begin = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    int leftMedian = begin;

    if (n % 2 == 0)
    {
        begin = tmpBegin;
        end = tmpEnd;

        while (begin < end)
        {
            int leftCounter = 0;
            int mid = (begin + end) / 2;
            if(tmpMid == mid) break;
            tmpMid = mid;

            if(!A.empty())
                leftCounter += std::upper_bound(A.begin(), A.end(), mid) - A.begin();
        
            if(!B.empty())
                leftCounter += std::upper_bound(B.begin(), B.end(), mid) - B.begin();

            if (leftCounter <= k)
            {
                begin = mid + 1;
            }
            else
            {
                end = mid;
            }
        }

        int rightMedian = begin;

        return (leftMedian + rightMedian) / 2.0f;
    }

    return begin;
}

double findMedianSortedArrays(const std::vector<int> &A, const std::vector<int> &B) 
{
    int n = A.size();
    int m = B.size();
    if (n > m)
        return findMedianSortedArrays(B, A); // Swapping to make A smaller
 
    int start = 0;
    int end = n;
    int realmidinmergedarray = (n + m + 1) / 2;
 
    while (start <= end) 
    {
        int mid = (start + end) / 2;
        int leftAsize = mid;
        int leftBsize = realmidinmergedarray - mid;
        int leftA = (leftAsize > 0) ? A[leftAsize - 1] : INT_MIN; // checking overflow of indices 
        int leftB = (leftBsize > 0) ? B[leftBsize - 1] : INT_MIN;
        int rightA = (leftAsize < n) ? A[leftAsize] : INT_MAX;
        int rightB = (leftBsize < m) ? B[leftBsize] : INT_MAX;
 
        // if correct partition is done
        if (leftA <= rightB and leftB <= rightA)
        {
            if ((m + n) % 2 == 0)
                return (std::max(leftA, leftB) + std::min(rightA, rightB)) / 2.0;
            return std::max(leftA, leftB);
        }
        else if (leftA > rightB)
        {
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return 0.0;
}

double solution(const std::vector<int> &A, const std::vector<int> &B)
{
    double ans = 0;
    int n = A.size();
    int m = B.size();

    if(n > m)
    {
        return solution(B, A);
    }

    int begin = 0;
    int end = n;
    int realMid = (n + m + 1) / 2;

    while(begin <= end)
    {
        int mid = (begin + end) / 2;

        // Partitionate the arrays.
        //
        int partitionA = mid;

        // When the array A is shifted to one direction
        // array B is shifted to the opposite direction.
        // Also the arrays must be partitionated in the same size.
        //
        int partitionB = realMid - mid;

        // Get the last item in the left partition of A.
        //
        int leftA = partitionA > 0 ? A[partitionA - 1] : INT_MIN;

        // Get the last item in the left partition of B.
        //
        int leftB = partitionB > 0 ? B[partitionB - 1] : INT_MIN;

        // Get the first item in the right bucket of A.
        //
        int rightA = partitionA < n ? A[partitionA] : INT_MAX;

        // Get the first item in the right bucket of B.
        //
        int rightB = partitionB < m ? B[partitionB] : INT_MAX;

        // Check if the patition is correct.
        // All the elements in the left bucket must be
        // less than all the elements in the right bucket.
        //
        if(leftA <= rightB && leftB <= rightA)
        {
            if((m + n) % 2 == 0)
            {
                ans = (std::max(leftA, leftB) + std::min(rightA, rightB)) / 2.0f;
                break;
            }
            else
            {
                ans = std::max(leftA, leftB);
                return ans;
            }
        }
        else if(leftA > rightB)
        {
            // Shift to the left side. The last element
            // in the left bucket of A is greater than
            // the first item in the right bucket of B.
            //
            end = mid - 1;
        }
        else
        {
            // Shift to the right side. The last element
            // in the left bucket of B is greater than
            // the first item in the right bucket of A.
            //
            begin = mid + 1;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    // std::vector<int> A = { -43, -25, -18, -15, -10, 9, 39, 40 };
    // std::vector<int> B = { -2 };

    std::vector<int> A = { 40,50,60 };
    std::vector<int> B = { 20,30,80,90 };

    // B.erase(B.begin() + 2, B.end());

    // int left = solution(A, B);
    // B.push_back(6);
    // A.erase(A.begin(), A.begin() + 1);
    // int right = solution(A, B);

    // std::cout << (left + right) / 2.0f << '\n';

    std::cout << solution(A, B) << '\n';

    
    return 0;
}
