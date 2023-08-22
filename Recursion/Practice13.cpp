/* print all subsets of string */

#include <bits/stdc++.h>
using namespace std;

void get(std::string temp, int index, std::string text)
{
    if (index == text.size())
    {
        std::cout << temp << '\n';
        return;
    }

    temp += text[index];
    get(temp, index + 1, text);
    temp.erase(temp.size() - 1);

    get(temp, index + 1, text);
}

int main()
{
    std::string text, temp;
    std::cin >> text;

    get(temp, 0, text);
}