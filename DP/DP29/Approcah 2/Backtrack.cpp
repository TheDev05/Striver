#include <bits/stdc++.h>
using namespace std;

int getCount(std::string text1, int index1, int index2)
{
    if (index1 >= index2)
        return 0;

    int val1 = 0, val2 = 0;
    if (text1[index1] == text1[index2])
    {
        return (getCount(text1, index1 + 1, index2 - 1));
    }
    else
    {
        val1 = 1 + getCount(text1, index1 + 1, index2);
        val2 = 1 + getCount(text1, index1, index2 - 1);
    }

    return std::min(val1, val2);
}

int main()
{
    std::string text;
    std::cin >> text;

    std::cout << getCount(text, 0, text.size() - 1);
}