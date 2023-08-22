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

    int last1 = num[n - 1], last2 = 0, last3 = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        last2 = num[i];
        if (i + 2 < n)
            last2 += last3;

        int curr = std::max(last1, last2);
        
        last3 = last1;
        last1 = curr;
    }

    std::cout << last1;
}