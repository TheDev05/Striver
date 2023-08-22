#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> num(n, std::vector<int>(2, 0));
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i][0] >> num[i][1];
    }

    std::vector<int> store[n];
    std::vector<int> indeg(n, 0);

    for (int i = 0; i < n; i++)
    {
        store[num[i][1]].push_back(num[i][0]);
        indeg[num[i][0]]++;
    }

    std::queue<int> inox;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            inox.push(i);
    }

    int count = 0;
    while (inox.size())
    {
        int local = inox.front();
        inox.pop();

        count++;

        for (auto i : num[local])
        {
            indeg[i]--;
            if (indeg[i] == 0)
                inox.push(i);
        }
    }

    if (count == n)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}