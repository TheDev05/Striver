# Standard LIS technique

1. for printing only size use LIS (MEMO/TAB)
2. for printing the required array or subsequence use Linear LIS with following intiution :

If(a<b<c) i.e elements are sorted and a is divisible by b and b is divisible by c or all a,b,c is divisible to each other, then the divisibility rules apply for any random element 'x'  as: if x is divisibe by c then it will definetly divisible by a & b.

# Standard LCS:
convert your memo solution of LIS in tabular then change else parameter to equal to 0, i.e if ```text1[i] != text2[i]``` then the ```storage[i][j] = 0```, beaucse if they are not equal then they can't lead this substring further and we stopped with them, and keep track of maximum.

LCS Table: sum or count all consecutive diagonal elements having 1 (or both charater are equal), thats why we maintain max variable.
