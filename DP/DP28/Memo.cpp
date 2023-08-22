#include <bits/stdc++.h>
using namespace std;

int getCount(std::string &text, std::string &temp, std::vector<std::vector<int>> &storage, int index1, int index2)
{
    if (index1 >= text.size() || index2 >= temp.size())
        return 0;

    if (storage[index1][index2] == -1)
    {
        int val1 = 0, val2 = 0, val3 = 0;
        if (text[index1] == temp[index2])
            val1 = 1 + getCount(text, temp, storage, index1 + 1, index2 + 1);
        else
        {
            val2 = getCount(text, temp, storage, index1 + 1, index2);
            val3 = getCount(text, temp, storage, index1, index2 + 1);
        }

        storage[index1][index2] = std::max({val1, val2, val3});
    }

    return storage[index1][index2];
}

int main()
{
    std::string text;
    std::cin >> text;

    std::string temp = text;
    reverse(temp.begin(), temp.end());

    std::vector<std::vector<int>> storage(text.size(), std::vector<int>(temp.size(), -1));
    std::cout << getCount(text, temp, storage, 0, 0);
}