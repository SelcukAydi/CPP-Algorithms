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
If this question would ask about all elements in the given array appears twice even times but one of the item appears once then a basic XOR would be efficient. However, in this case, we have items appear odd number of times and one unique item in the given array. Finding the item that appears once is a little bit tricky.

The solution is using two variables. Suppose we have the given array A, `[1,1,1,4]`. The first variable stores the items that appear once until that time. The second variable stores the items that appear twice until that time. The first variable is always XOR'ed with the current item in the for loop. If this current item appears second time in the array then first variable will be cleared and the second variable will store this item.

We are adding the first item. We store 1 into the first variable by XOR. Now we are at the second item. This one is again 1. We check if this item is already stored in the first variable. If yes then it means that we can record this in the second variable. This item is again XOR'ed with the first variable and 1 is removed from the first variable. However, we still have the 1 in the second variable. Now we are adding 1 third times. We realize that we have this variable two times already. Also we XOR the first variable and the current item. Now we have 1 in the first variable and in the second variable. We remove the common bits. So we do not have 1 in any variable any more. Now we are adding 4. This time the first variable will always record 4 and that will be what we have been looking for. Understanding the first part is enough to understand the whole problem and its solution. Removing items appearing three times is the core and root logic behind this solution.

**Note:** Adding 1 and then 3 will be interesting. When you XOR a variable with 1 and then 3 will result in adding two times 1 and one time 2. This is because of that 3 has 011 bit representation. Also think about adding 1 XOR 2 XOR 3. This will result in zero. Cause you have removed all the common bit representations.
**Note:** If we are dialing with bits then always think at bit level. This will help you understand the bitwise operations and their real purpose.

