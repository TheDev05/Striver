#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::string text1, text2;
    std::cin >> text1 >> text2;

    std::vector<std::vector<int>> storage(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));

    int max = INT_MIN;
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = storage[0].size() - 2; j >= 0; j--)
        {
            if (text1[i] == text2[j])
                storage[i][j] = 1 + storage[i + 1][j + 1];

            max = std::max(max, storage[i][j]);
        }
    }

    std::cout << max << '\n';
}