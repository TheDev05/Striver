# Method 1:

Using for loop in main function then for every element call recursive function.

FAIL: can’t use DP using this method

# Method 2:

Using take and not take concept, keeping track of previous element in some “temp” variable

FAIL: DP gets fail as element can be negative, and we have 2 varing varible index & temp, when storing both in DP table, the negative elemnts or temp cause error as there are no neg index in DP table

# Method 3:

Using method 2 but keeping track of indices instead of array element, providing -1 intially to “temp”

FAIL: DP fails with negative values

# Method 4:

Using 3 but passing 0 initially and shift array indices forward.

NOTE: Printing OF LIS:
2 ways to print LIS:

- nLogn: Using binary search
- n*n: using linear DP

[Solution](https://leetcode.com/submissions/detail/888677061/) 

Similar: [https://leetcode.com/problems/best-team-with-no-conflicts/](https://leetcode.com/problems/best-team-with-no-conflicts/)