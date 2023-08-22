#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    int last = 0, last2 = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int val1 = last + abs(num[i] - num[i + 1]);
        int val2 = INT_MAX;

        if (i < n - 2)
            val2 = last2 + abs(num[i] - num[i + 2]);

        int curr = std::min(val1, val2);

        last2 = last;
        last = curr;
    }

    std::cout << last << '\n';
}