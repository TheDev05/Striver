/* Basic */

#include <bits/stdc++.h>

int count = 0;
int fun()
{
    // base condition, when count hits the value '5', Terminates & return!
    if (count == 5)
    {
        return (0);
    }

    std::cout << count << '\n';
    count++;

    fun();
    std::cout << count << '\n';
    count--;

    return (0);
}

int main()
{
    fun();
}