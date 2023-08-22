#include <bits/stdc++.h>
using namespace std;

std::string getCount(std::string text1, std::string text2, int index1, int index2)
{
    if (index1 >= text1.size() || index2 >= text2.size())
        return "";

    std::string val1, val2, val3;
    if (text1[index1] == text2[index2])
    {
        val1 = text1[index1] + getCount(text1, text2, index1 + 1, index2 + 1);
    }
    else
    {
        val2 = getCount(text1, text2, index1, index2 + 1);
        val3 = getCount(text1, text2, index1 + 1, index2);
    }

    if (val1.size() > std::max(val2.size(), val3.size()))
        return val1;
    if (val2.size() > std::max(val1.size(), val3.size()))
        return val2;
    return val3;
}

int main()
{
    std::string text1, text2;
    std::cin >> text1 >> text2;

    std::cout << getCount(text1, text2, 0, 0);
}