/* Print name 5 times */

#include <bits/stdc++.h>

int count = 1;
int foo(std::string text)
{
    if (count == 6)
    {
        return (0);
    }

    std::cout << text << '\n';
    count++;

    foo(text);
    return (0);
}

int main()
{
    std::string text = "ANKIT";
    foo(text);
}