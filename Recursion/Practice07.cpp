/* Check string is palindrome or not */

#include <bits/stdc++.h>
using namespace std;

int foo(int i, std::string text)
{
    if (i >= text.size())
    {
        return (1);
    }

    if (text[i] != text[text.size() - 1 - i])
    {
        return (0);
    }

    return (foo(i + 1, text));
}

int main()
{
    std::string text;
    std::cin >> text;

    int i = 0;
    if (foo(i, text))
    {
        std::cout << "YES\n";
    }
    else
        std::cout << "NO\n";
}