#include <iostream>
#include <vector>

int search(const std::vector<int> &A, int B)
{
    int ans = -1;
    int n = A.size();
    int begin = 0;
    int end = n - 1;
    bool pivotFound = false;

    while (begin <= end)
    {
        int mid = (begin + end) / 2;

        if (A[mid] == B)
        {
            ans = mid;
            break;
        }

        if (!pivotFound)
        {
            if (mid < n - 1 && A[mid] > A[mid + 1])
            {
                //std::cout << "Pivot is " << A[mid + 1] << '\n';
                pivotFound = true;

                if (B > A[n - 1])
                {
                    begin = 0;
                    end = mid;
                }
                else
                {
                    begin = mid + 1;
                    end = n;
                }

                continue;
            }
            else if (mid > 0 && A[mid - 1] > A[mid])
            {
                //std::cout << "Pivot is " << A[mid] << '\n';
                pivotFound = true;

                if (B > A[n - 1])
                {
                    begin = 0;
                    end = mid - 1;
                }
                else
                {
                    begin = mid;
                    end = n;
                }

                continue;
            }

            if (A[mid] < A[begin])
            {
                end = mid - 1;
            }
            else if (A[mid] > A[end])
            {
                begin = mid + 1;
            }
            else
            {
                //std::cout << "begin:" << begin << " and end:" << end << " interval is sorted.\n";
                if (A[mid] < B)
                {
                    begin = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        else
        {
            if (A[mid] < B)
            {
                begin = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return ans;
}

int search1(const std::vector<int> &A, int B)
{
    int ans = -1;
    int n = A.size();
    int begin = 0;
    int end = n - 1;

    while(begin <= end)
    {
        int mid = (begin + end) / 2;

        if(A[mid] == B)
        {
            ans = mid;
            break;
        }

        if(A[0] <= A[mid]) // Left part is sorted.
        {
            if(B < A[mid] && B >= A[0]) end = mid - 1;
            else begin = mid + 1;
        }
        else // Right part is sorted.
        {
           if(A[n - 1] >= B && B > A[mid]) begin = mid + 1;
           else end = mid - 1;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6};
    std::vector<int> v2 = {180, 181, 182, 183, 184, 187, 188, 189, 191, 192, 193, 194, 195, 196, 201, 202, 203, 204, 3, 4, 5, 6, 7, 8, 9, 10, 14, 16, 17, 18, 19, 23, 26, 27, 28, 29, 32, 33, 36, 37, 38, 39, 41, 42, 43, 45, 48, 51, 52, 53, 54, 56, 62, 63, 64, 67, 69, 72, 73, 75, 77, 78, 79, 83, 85, 87, 90, 91, 92, 93, 96, 98, 99, 101, 102, 104, 105, 106, 107, 108, 109, 111, 113, 115, 116, 118, 119, 120, 122, 123, 124, 126, 127, 129, 130, 135, 137, 138, 139, 143, 144, 145, 147, 149, 152, 155, 156, 160, 162, 163, 164, 166, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177};
    std::vector<int> v3 = {101, 103, 106, 109, 158, 164, 182, 187, 202, 205, 2, 3, 32, 57, 69, 74, 81, 99, 100};
    std::vector<int> v4 = { 2,1 };
    
    std::cout << search1(v4, 1) << '\n';

    return 0;
}
