#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::string text1, text2;
    std::cin >> text1 >> text2;

    if (text2.size() > text1.size())
        swap(text1, text2);

    std::vector<std::vector<int>> storage(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));

    for (int i = 0; i < storage[0].size(); i++)
        storage[storage.size() - 1][i] = text2.size() - i;
    for (int i = 0; i < storage.size(); i++)
        storage[i][storage[0].size() - 1] = text1.size() - i;

    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = storage[0].size() - 2; j >= 0; j--)
        {
            int val1 = 1e5, val2 = 1e5, val3 = 1e5, val4 = 1e5;
            if (text1[i] == text2[j])
            {
                val1 = storage[i + 1][j + 1];
            }
            else
            {
                // delete
                val2 = 1 + storage[i + 1][j];
                // replace
                val3 = 1 + storage[i + 1][j + 1];
                // insert
                val4 = 1 + storage[i][j + 1];
            }

            storage[i][j] = std::min({val1, val2, val3, val4});
        }
    }

    std::cout<<storage[0][0];
}