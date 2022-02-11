You are looking for the longest leading fragment (prefix) of an array A in which there is an equal number of occurrences of X, and Y, where X and Y are integers.

For example, where X=7 and Y=42, the longest prefix where A=[6, 42, 11, 7, 1, 42] would be 4, because A[0]-A[4] contain the same number of X and Y.

Another example, X=6 and Y=13. A=[13,13,1,6]. The function should return -1, because there is no prefix.

X=100, Y=63, and A=[100,63,1,6,2,13] should return 5.

