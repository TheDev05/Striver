#include <bits/stdc++.h>
using namespace std;

std::string getCount(std::string text1, std::string text2, std::vector<std::vector<std::string>> &storage, int index1, int index2)
{
    if (index1 >= text1.size() || index2 >= text2.size())
        return "";

    if (storage[index1][index2] == "0")
    {
        std::string val1, val2, val3;
        if (text1[index1] == text2[index2])
        {
            val1 = text1[index1] + getCount(text1, text2, storage, index1 + 1, index2 + 1);
        }
        else
        {
            val2 = getCount(text1, text2, storage, index1, index2 + 1);
            val3 = getCount(text1, text2, storage, index1 + 1, index2);
        }

        std::string inox;
        if (val1.size() > std::max(val2.size(), val3.size()))
            inox = val1;
        else if (val2.size() > std::max(val1.size(), val3.size()))
            inox = val2;
        else
            inox = val3;

        storage[index1][index2] = inox;
    }

    return storage[index1][index2];
}

int main()
{
    std::string text1, text2;
    std::cin >> text1 >> text2;

    std::vector<std::vector<std::string>> storage(text1.size(), std::vector<std::string>(text2.size(), "0"));
    std::cout << getCount(text1, text2, storage, 0, 0);
}