# Problem Description
Link : https://www.geeksforgeeks.org/find-the-element-that-appears-once/

Given an array where every element occurs three times, except one element which occurs only once. Find the element that occurs once. The expected time complexity is O(n) and O(1) extra space. 

**Examples**


    Input: arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3} 
    Output: 2 
In the given array all element appear three times except 2 which appears once.



    Input: arr[] = {10, 20, 10, 30, 10, 30, 30} 
    Output: 20 
In the given array all element appear three times except 20 which appears once.

# Solution Explanation
We have an array that has items repeating three times except one. This exceptional item appears once in the whole array. We desire to find this special item in the array. There are many solutions of this problem but we are looking forward the most efficient one. That's why we use bitwise operations.
The approach is simple as following:
1. If we see the current item for the first time then store it in the variable "ones".
2. If we see the current item for the second time then store it in the variable "twos".
3. If we see the current item for the third time then remove it from the "ones" and "twos".

To be able to understand this problem's solution deeply you need to change your persective. We indeed do not store a item in any of these two variables. We store "bit patterns" of the corresponding item in the array. As a result, the first variable "ones" stores only the bits that appear once. If these bits appear for the second time then they will be remove from the "ones" by using XOR and we store these bits in the second variable "twos". If any of these bits appear for the third time then we remove these common bits from the "ones" and "twos".
> *Please note that if you are looking for a solution in the bitwise world then you have to think from the perspective of bits not the values that are represented by bits.*
