/* Maximum in an array */
/* Down to Up approach*/

#include <bits/stdc++.h>
using namespace std;

int get(vector<int> num, int index, int maxim)
{
    if (index == num.size() - 1)
    {
        return (num[index]);
    }

    return (std::max(num[index], get(num, index + 1, maxim)));
}

int main()
{
    int n;
    std::cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    std::cout << get(num, 0, INT_MIN);
}