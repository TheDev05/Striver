#include <bits/stdc++.h>
using namespace std;

int getCount(std::string text1, std::string text2, int index1, int index2)
{
    if (index1 >= text1.size() || index2 >= text2.size())
        return 0;

    int val1 = 0, val2 = 0, val3 = 0;
    if (text1[index1] == text2[index2])
        val1 = 1 + getCount(text1, text2, index1 + 1, index2 + 1);
    val2 = getCount(text1, text2, index1 + 1, index2);
    val3 = getCount(text1, text2, index1, index2 + 1);

    return (std::max({val1, val2, val3}));
}

int main()
{
    std::string text1, text2;
    std::cin >> text1 >> text2;

    std::cout << getCount(text1, text2, 0, 0);
}