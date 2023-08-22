#include <bits/stdc++.h>
using namespace std;

int getCount(std::string text1, std::string text2, std::string temp, std::string &result, int index1, int index2)
{
    if (index1 >= text1.size() || index2 >= text2.size())
    {
        if (temp.size() > result.size())
            result = temp;

        return 0;
    }

    if (text1[index1] == text2[index2])
    {
        getCount(text1, text2, temp + text1[index1], result, index1 + 1, index2 + 1);
    }
    else
    {
        getCount(text1, text2, temp, result, index1, index2 + 1);
        getCount(text1, text2, temp, result, index1 + 1, index2);
    }

    return 0;
}

int main()
{
    std::string text1, text2;
    std::cin >> text1 >> text2;

    std::string temp, result;
    getCount(text1, text2, temp, result, 0, 0);

    std::cout << result;
}