#include <bits/stdc++.h>
using namespace std;

bool check(std::vector<int> num[], std::vector<int> &vis, int start, int n)
{
    std::queue<int> qt;

    qt.push(start);
    vis[start] = 1;

    bool ok = false;
    while (qt.size())
    {
        int inox = qt.front();
        qt.pop();

        int count = 0;
        for (auto i : num[inox])
        {
            if (vis[i])
                count++;
            else
            {
                qt.push({i, inox});
                vis[i] = 1;
            }
        }

        if (count > 1)
            ok = true;
    }

    return ok;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> num[n];
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;

        for (int j = 0; j < temp; j++)
        {
            int val;
            std::cin >> val;

            num[i].push_back(val);
        }
    }

    std::vector<int> vis(n, 0);

    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
            ok |= check(num, vis, i, n);
    }

    std::cout << ok;
}