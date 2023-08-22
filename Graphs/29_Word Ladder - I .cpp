#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::string first, last;
    std::cin >> first >> last;

    int n;
    std::cin >> n;

    std::vector<std::string> num(n);
    for (auto &i : num)
        std::cin >> i;

    std::set<std::string> vis, exist;
    std::queue<std::pair<std::string, int>> inox;

    for (auto i : num)
        exist.insert(i);

    inox.push({first, 1});
    vis.insert(first);

    int count = 0;
    while (inox.size())
    {
        std::string local = inox.front().first;
        int level = inox.front().second;

        inox.pop();
        if (local == last)
        {
            count = level;
            break;
        }

        for (int i = 0; i < local.size(); i++)
        {
            std::string temp = local;
            char alpha = 'a';

            for (int j = 0; j < 26; j++)
            {
                local[i] = alpha;
                alpha++;

                if (vis.count(local) == false && exist.count(local))
                {
                    vis.insert(local);
                    inox.push({local, level + 1});
                }
            }

            local = temp;
        }
    }

    std::cout << count;
}