#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::string num[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    std::vector<int> store[n];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < std::min(num[i].size(), num[i + 1].size()); j++)
        {
            if (num[i][j] != num[i + 1][j])
            {
                store[num[i][j] - 'a'].push_back(num[i + 1][j] - 'a');
                break;
            }
        }
    }

    std::vector<int> indeg(k, 0);
    for (int i = 0; i < k; i++)
    {
        for (auto j : store[i])
            indeg[j]++;
    }

    std::queue<int> inox;
    for (int i = 0; i < k; i++)
    {
        if (indeg[i] == 0)
            inox.push(i);
    }

    std::string text;
    while (inox.size())
    {
        int local = inox.front();
        inox.pop();

        text += (char)(local + 'a');

        for (auto i : store[local])
        {
            indeg[i]--;
            if (indeg[i] == 0)
                inox.push(i);
        }
    }

    std::cout << text;
}