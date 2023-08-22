#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::string text1, text2;
    std::cin >> text1 >> text2;

    std::vector<int> prev(text2.size() + 1, 0), curr(text2.size() + 1, 0);
    for (int i = text1.size() - 1; i >= 0; i--)
    {
        for (int j = curr.size() - 2; j >= 0; j--)
        {
            int val1 = 0, val2 = 0, val3 = 0;
            if (text1[i] == text2[j])
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

    int count = curr[0];
    std::cout << (text1.size() - count) + (text2.size() - count);
}