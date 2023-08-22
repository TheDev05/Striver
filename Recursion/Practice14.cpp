#include <bits/stdc++.h>
using namespace std;

void write(vector<int> num, int index)
{
    if (index == num.size())
        return;

    std::cout << num[index] << " ";
    write(num, index + 1);
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

    write(num, 0);

    return (0);
}