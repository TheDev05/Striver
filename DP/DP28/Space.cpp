#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::string text;
    std::cin >> text;

    std::string temp = text;
    reverse(temp.begin(), temp.end());

    std::vector<int> prev(temp.size() + 1, 0), curr(temp.size() + 1, 0);
    for (int i = text.size() - 1; i >= 0; i--)
    {
        for (int j = prev.size() - 2; j >= 0; j--)
        {
            int val1 = 0, val2 = 0, val3 = 0;
            if (text[i] == temp[j])
                val1 = 1 + prev[j + 1];
            else
            {
                val2 = prev[j];
                val3 = curr[j + 1];
            }

            curr[j] = std::max({val1, val2, val3});
        }

        prev = curr;
    }

    std::cout << curr[0];
}