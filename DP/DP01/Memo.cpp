#include <bits/stdc++.h>
using namespace std;

int fib(int n, std::vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] == -1)
    {
        dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    }

    return dp[n];
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> dp(n + 1, -1);
    std::cout << fib(n, dp) << '\n';
}