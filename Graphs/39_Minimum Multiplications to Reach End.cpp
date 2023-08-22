#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> num(n);
    for (auto i : num)
        std::cin >> i;

    int start, end;
    std::cin >> start >> end;

    int mod = 100000;

    std::queue<std::pair<int, int>> inox;
    std::vector<int> dist(mod, 1e7);

    inox.push({start, 0});
    dist[start] = 0;

    while (inox.size())
    {
        auto it = inox.front();
        inox.pop();

        int val = it.first;
        int lvl = it.second;

        for (auto i : num)
        {
            int prod = (val * i) % mod;
            if (lvl + 1 < dist[prod])
            {
                dist[prod] = lvl + 1;
                inox.push({prod, dist[prod]});
            }

            if (prod == end)
                break;
        }
    }

    std::cout << dist[end];
}