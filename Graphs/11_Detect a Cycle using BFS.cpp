#include <bits/stdc++.h>
using namespace std;

bool check(std::vector<int> num[], std::vector<int> &vis, int start, int n)
{
    std::queue<std::pair<int, int>> qt;

    qt.push({start, -1});
    vis[start] = 1;

    bool ok = false;
    while (qt.size())
    {
        int inox = qt.front().first;
        int parent = qt.front().second;

        qt.pop();

        for (auto i : num[inox])
        {
            if (vis[i])
            {
                if (i != parent)
                    ok = true;
            }
            else
            {
                qt.push({i, inox});
                vis[i] = 1;
            }
        }
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