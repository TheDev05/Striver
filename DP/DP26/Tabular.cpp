#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::string text1, text2;
    std::cin >> text1 >> text2;

    std::vector<std::vector<std::string>> storage(text1.size() + 1, std::vector<std::string>(text2.size() + 1, ""));
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = storage[0].size() - 2; j >= 0; j--)
        {
            std::string val1, val2, val3;
            if (text1[i] == text2[j])
            {
                val1 = text1[i] + storage[i + 1][j + 1];
            }
            else
            {
                val2 = storage[i + 1][j];
                val3 = storage[i][j + 1];
            }

            std::string inox;
            if (val1.size() > std::max(val2.size(), val3.size()))
                inox = val1;
            else if (val2.size() > std::max(val1.size(), val3.size()))
                inox = val2;
            else
                inox = val3;

            storage[i][j] = inox;
        }
    }

    std::cout << storage[0][0];
}