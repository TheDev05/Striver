#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::string text1, text2;
    std::cin >> text1 >> text2;

    if (text2.size() > text1.size())
        swap(text1, text2);

    std::vector<int> prev(text2.size() + 1, 0), curr(text2.size() + 1, 0);

    for (int i = 0; i < prev.size(); i++)
        prev[i] = text2.size() - i;

    for (int i = text1.size() - 1; i >= 0; i--)
    {
        curr[curr.size() - 1] = text1.size() - i;
        for (int j = curr.size() - 2; j >= 0; j--)
        {
            int val1 = 1e5, val2 = 1e5, val3 = 1e5, val4 = 1e5;
            if (text1[i] == text2[j])
            {
                val1 = prev[j + 1];
            }
            else
            {
                // delete
                val2 = 1 + prev[j];
                // replace
                val3 = 1 + prev[j + 1];
                // insert
                val4 = 1 + curr[j + 1];
            }

            curr[j] = std::min({val1, val2, val3, val4});
        }

        prev = curr;
    }

    std::cout << curr[0];
}