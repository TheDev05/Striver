#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::string text1, text2;
    std::cin >> text1 >> text2;

    std::vector<int> prev(text2.size() + 1, 0);

    int max = INT_MIN;
    for (int i = text1.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < prev.size() - 1; j++)
        {
            if (text1[i] == text2[j])
                prev[j] = 1 + prev[j + 1];
            else
                prev[j] = 0;

            max = std::max(max, prev[j]);
        }
    }

    std::cout << max << '\n';
}