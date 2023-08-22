#include <bits/stdc++.h>
using namespace std;

int getCount(std::string &text1, std::string &text2, std::vector<std::vector<int>> &storage, int index1, int index2)
{
    if (index1 >= text1.size() || index2 >= text2.size())
        return 0;

    if (storage[index1][index2] == -1)
    {
        int val1 = 0, val2 = 0, val3 = 0;
        if (text1[index1] == text2[index2])
            val1 = 1 + getCount(text1, text2, storage, index1 + 1, index2 + 1);
        else
        {
            val2 = getCount(text1, text2, storage, index1 + 1, index2);
            val3 = getCount(text1, text2, storage, index1, index2 + 1);
        }

        storage[index1][index2] = std::max({val1, val2, val3});
    }

    return storage[index1][index2];
}

int main()
{
    std::string text1, text2;
    std::cin >> text1 >> text2;

    std::vector<std::vector<int>> storage(text1.size(), std::vector<int>(text2.size(), -1));

    int count = getCount(text1, text2, storage, 0, 0);
    std::cout << (text1.size() - count) + (text2.size() - count);
}