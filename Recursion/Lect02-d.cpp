#include <bits/stdc++.h>
using namespace std;

void printCount(int n)
{
    if (n < 1)
    {
        return;
    }

    printCount(n - 1);
    std::cout << n << '\n';
}

int main()
{
    int n;
    std::cin >> n;

    printCount(n);
}