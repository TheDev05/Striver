#include <bits/stdc++.h>
using namespace std;

vector<int> num;

void rev(int i, int n)
{
    if (i >= n / 2)
    {
        return;
    }

    swap(num[i], num[n - 1 - i]);

    rev(i + 1, n);
}

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        int val;
        std::cin >> val;

        num.push_back(val);
    }

    rev(0, n);

    for (int i = 0; i < n; i++)
    {
        std::cout << num[i] << " ";
    }
}