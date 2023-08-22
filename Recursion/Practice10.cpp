/* Power of 2 */

#include <bits/stdc++.h>
using namespace std;

int get(int n)
{
    if (n == 0)
    {
        return (1);
    }

    return (2 * get(n - 1));
}

int main()
{
    int n;
    std::cin >> n;

    // find: (2^n)??

    std::cout << get(n);
}