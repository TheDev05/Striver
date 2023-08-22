#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::string text1, text2;
    std::cin >> text1 >> text2;

    std::vector<std::vector<int>> storage(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = storage[0].size() - 2; j >= 0; j--)
        {
            if (text1[i] == text2[j])
                storage[i][j] = 1 + storage[i + 1][j + 1];
            else
                storage[i][j] = std::max(storage[i + 1][j], storage[i][j + 1]);
        }
    }

    std::cout << (text1.size() + text2.size()) - storage[0][0] << '\n';

    int i = 0, j = 0;
    std::string result;

    while (i < text1.size() && j < text2.size())
    {
        if (text1[i] == text2[j])
        {
            result += text1[i];

            i++;
            j++;
        }
        else
        {
            if (storage[i + 1][j] < storage[i][j + 1])
            {
                result += text2[j];
                j++;
            }
            else
            {
                result += text1[i];
                i++;
            }
        }
    }

    while (i < text1.size())
    {
        result += text1[i];
        i++;
    }

    while (j < text2.size())
    {
        result += text2[j];
        j++;
    }

    std::cout << result;
}