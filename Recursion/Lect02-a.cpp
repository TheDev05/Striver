#include <bits/stdc++.h>
using namespace std;

void printName(std::string text, int i, int n)
{
    if (i > n)
    {
        return;
    }

    std::cout << text << '\n';

    printName(text, i + 1, n);
}

int main()
{
    int n;
    std::cin >> n;

    std::string text = "Ankit";

    printName(text, 1, n);
}