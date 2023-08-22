#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    std::vector<std::vector<bool>> storage(n + 1, std::vector<bool>(k + 1, false));
    storage[storage.size() - 1][storage[0].size() - 1] = true;

    bool result = false;
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < storage[0].size(); j++)
        {
            int index = j + num[i];
            if (index >= storage[0].size())
                continue;

            for (int k = i + 1; k < storage.size(); k++)
            {
                if (storage[k][index])
                {
                    storage[i][j] = true;
                    break;
                }
            }

            if (j == 0 && storage[i][j] == true)
                result = true;
        }
    }

    std::cout << result;
}