#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    std::cin >> n;

    int last2 = 0, last1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = last1 + last2;

        last2 = last1;
        last1 = curr;
    }

    std::cout << last1 << '\n';
}