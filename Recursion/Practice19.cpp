/* Index of a particular element */
#include <bits/stdc++.h>
using namespace std;

int get(vector<int> num, int index, int inox)
{
    if (index == num.size())
    {
        return (index);
    }

    if (inox == num[index])
    {
        return (index);
    }

    return (get(num, index + 1, inox));
}

int main()
{
    int n;
    std::cin >> n;

    int findme;
    std::cin >> findme;

    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    std::cout << "INDEX: " << get(num, 0, findme) + 1;
}