#include <bits/stdc++.h>
using namespace std;

void printCount(int i, int n)
{
    if (i > n)
    {
        return;
    }

    printCount(i + 1, n);
    std::cout << i << '\n';
}

int main()
{
    int n;
    std::cin >> n;

    printCount(1, n);
}