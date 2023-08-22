#include <bits/stdc++.h>
using namespace std;

int getCount(std::string &text1, std::string &text2, std::vector<std::vector<int>> &storage, int index1, int index2)
{
    if (index2 >= text2.size())
        return (text1.size() - index1);
    else if (index1 >= text1.size())
        return (text2.size() - index2);

    if (storage[index1][index2] == -1)
    {
        int val1 = 1e5, val2 = 1e5, val3 = 1e5, val4 = 1e5;
        if (text1[index1] == text2[index2])
        {
            val1 = getCount(text1, text2, storage, index1 + 1, index2 + 1);
        }
        else
        {
            // delete
            val2 = 1 + getCount(text1, text2, storage, index1 + 1, index2);
            // replace
            val3 = 1 + getCount(text1, text2, storage, index1 + 1, index2 + 1);
            // insert
            val4 = 1 + getCount(text1, text2, storage, index1, index2 + 1);
        }

        storage[index1][index2] = std::min({val1, val2, val3, val4});
    }

    return storage[index1][index2];
}

int main()
{
    std::string text1, text2;
    std::cin >> text1 >> text2;

    if (text2.size() > text1.size())
        swap(text1, text2);

    std::vector<std::vector<int>> storage(text1.size(), std::vector<int>(text2.size(), -1));
    std::cout << getCount(text1, text2, storage, 0, 0);
}