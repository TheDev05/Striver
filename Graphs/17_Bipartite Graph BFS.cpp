#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> num;
    for (int i = 0; i < n; i++)
    {
        int m;
        std::cin >> m;

        std::vector<int> temp(m);
        for (auto &j : temp)
            std::cin >> j;

        num.push_back(temp);
    }

    std::vector<int> inox(n, -1);
    std::queue<int> temp;

    int color = 0;
    bool ok = false;

    for (int i = 0; i < n; i++)
    {
        if (inox[i] == -1)
        {
            temp.push(i);
            inox[i] = color;

            while (temp.size())
            {
                int local = temp.front();
                temp.pop();

                for (auto i : num[local])
                {
                    if (inox[i] == -1)
                    {
                        inox[i] = (color) ? 0 : 1;
                        color = inox[i];

                        temp.push(i);
                    }
                    else if (inox[i] == inox[local])
                    {
                        // return false;

                        ok = true;
                        break;
                    }
                }

                if (ok)
                    break;
            }
        }

        if (ok)
            break;
    }

    std::cout << !ok;
}