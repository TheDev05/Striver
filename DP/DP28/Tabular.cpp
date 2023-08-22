#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::string text;
    std::cin >> text;

    std::string temp = text;
    reverse(temp.begin(), temp.end());

    std::vector<std::vector<int>> storage(text.size() + 1, std::vector<int>(temp.size() + 1, 0));
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = storage[0].size() - 2; j >= 0; j--)
        {
            int val1 = 0, val2 = 0, val3 = 0;
            if (text[i] == temp[j])
                val1 = 1 + storage[i + 1][j + 1];
            else
            {
                val2 = storage[i + 1][j];
                val3 = storage[i][j + 1];
            }

            storage[i][j] = std::max({val1, val2, val3});
        }
    }

    std::cout << storage[0][0];
}