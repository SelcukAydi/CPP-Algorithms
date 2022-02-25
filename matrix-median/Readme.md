# Matrix Median
The location of this question is at [matrix-median.](https://www.interviewbit.com/problems/matrix-median/ "matrix-media.")
## Question
Given a matrix of integers A of size N x M in which each row is sorted. Find an return the overall median of the matrix A. 
**Note:** No extra memory is allowed.
**Note:** Rows are numbered from top to bottom and columns are numbered from left to right.

For example;

`A = { {1,3,5}, {2,6,9}, {3,6,9} }`

**A** is sorted as `1, 2, 3, 3, 5, 6, 6, 9, 9` hence we return 5 cause it is the median.

## Solution
Binary search is used for this solution. We find the min and max items in the matrix and use binary search to find the median in this range. For example let's assume `A = { {1,2,3,4,5} }`. Here if we find that 3 has two items on the left side we can solve this problem. However, 3 may appear more than once like `A = { {1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3} }` so here 2 is the median but which one? To be able to find how many items less than the current candidate we can use std::upper_bound method. This method returns the first item bigger than the candidate. However, here, this method will count all the 2's as well. So it will return 6 for candidate 2. This is not what we are looking for. This may be solved easily. Suppose our candidate is 1 currently. We find that we have only one item on the left side. So our expectation is 2 items on the left side of the median.  This is not median. However, we have just found the number of items on the left side for candidate + 1 which is 2 here. Since std::upper_bound counts the candidate too, we eliminated this weakness. Conclusion is that, for any candidate we find the number of items on the left side for candidate + 1 in the range.
