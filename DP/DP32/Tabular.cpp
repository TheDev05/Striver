#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::string text1, text2;
    std::cin >> text1 >> text2;

    std::vector<std::vector<int>> storage(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));
    for (int i = 0; i < storage.size(); i++)
        storage[i][storage[0].size() - 1] = 1;

    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = storage[0].size() - 2; j >= 0; j--)
        {
            int val1 = 0, val2 = 0;
            if (text1[i] == text2[j])
            {
                val1 = storage[i + 1][j + 1];
                val2 = storage[i + 1][j];
            }
            else
                val2 = storage[i + 1][j];

            storage[i][j] = val1 + val2;
        }
    }

    std::cout << storage[0][0];
}