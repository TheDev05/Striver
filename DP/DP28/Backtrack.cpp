#include <bits/stdc++.h>
using namespace std;

int getCount(std::string text, std::string temp, int index1, int index2)
{
    if (index1 >= text.size() || index2 >= temp.size())
        return 0;

    int val1 = 0, val2 = 0, val3 = 0;
    if (text[index1] == temp[index2])
        val1 = 1 + getCount(text, temp, index1 + 1, index2 + 1);
    else
    {
        val2 = getCount(text, temp, index1 + 1, index2);
        val3 = getCount(text, temp, index1, index2 + 1);
    }

    return std::max({val1, val2, val3});
}

int main()
{
    std::string text;
    std::cin >> text;

    std::string temp = text;
    reverse(temp.begin(), temp.end());

    std::cout << getCount(text, temp, 0, 0);
}