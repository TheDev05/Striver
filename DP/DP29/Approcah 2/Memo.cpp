#include <bits/stdc++.h>
using namespace std;

int getCount(std::string text1, std::vector<std::vector<int>> storage, int index1, int index2)
{
    if (index1 >= index2)
        return 0;

    if (storage[index1][index2] == -1)
    {
        int val1 = 0, val2 = 0;
        if (text1[index1] == text1[index2])
        {
            return (getCount(text1, storage, index1 + 1, index2 - 1));
        }
        else
        {
            val1 = 1 + getCount(text1, storage, index1 + 1, index2);
            val2 = 1 + getCount(text1, storage, index1, index2 - 1);
        }

        storage[index1][index2] = std::min(val1, val2);
    }

    return storage[index1][index2];
}

int main()
{
    std::string text;
    std::cin >> text;

    std::vector<std::vector<int>> storage(text.size(), std::vector<int>(text.size(), -1));
    std::cout << getCount(text, storage, 0, text.size() - 1);
}