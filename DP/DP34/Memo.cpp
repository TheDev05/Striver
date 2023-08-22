#include <bits/stdc++.h>
using namespace std;

int getCount(std::string &text1, std::string &text2, std::vector<std::vector<int>> &storage, bool ok, int index1, int index2)
{
    if (index1 >= text1.size() && index2 >= text2.size())
        return 1;

    if (index2 >= text2.size())
    {
        for (int i = index1; i < text1.size(); i++)
        {
            if (text1[i] != '*')
                return 0;
        }

        return 1;
    }

    if (index1 >= text1.size())
        return 0;

    if (storage[index1][index2] == -1)
    {
        if (text1[index1] == text2[index2] || text1[index1] == '?')
        {
            if (getCount(text1, text2, storage, false, index1 + 1, index2 + 1))
                return true;
        }

        if (text1[index1] == '*')
        {
            if (getCount(text1, text2, storage, true, index1 + 1, index2))
                return true;
            if (getCount(text1, text2, storage, true, index1, index2 + 1))
                return true;
        }

        storage[index1][index2] = false;
    }

    return storage[index1][index2];
}

int main()
{
    std::string text1, text2;
    std::cin >> text1 >> text2;

    std::vector<std::vector<int>> storage(text1.size(), std::vector<int>(text2.size(), -1));
    std::cout << getCount(text1, text2, storage, false, 0, 0) << '\n';
}