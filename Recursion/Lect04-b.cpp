#include <bits/stdc++.h>
using namespace std;

bool isPalin(int i, int n, std::string text)
{
    if (i >= n / 2)
    {
        return true;
    }

    if (text[i] != text[n - 1 - i])
    {
        return false;
    }

    return (isPalin(i + 1, n, text));
}

int main()
{
    std::string text;
    std::cin >> text;

    std::cout << isPalin(0, text.size(), text);
}