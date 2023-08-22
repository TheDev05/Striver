#include <bits/stdc++.h>
using namespace std;

void printCount(int n)
{
    if (n < 1)
    {
        return;
    }

    std::cout << n << '\n';
    printCount(n - 1);
}

int main()
{
    int n;
    std::cin >> n;

    printCount(n);
}