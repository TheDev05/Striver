#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::string> res(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> res[i];
    }

    std::vector<std::pair<int, std::string>> num;
    for (int i = 0; i < res.size(); i++)
    {
        num.push_back({res[i].size(), res[i]});
    }

    sort(num.begin(), num.end());

    std::vector<int> storage(num.size(), 1);

    int result = 0;
    for (int i = 0; i < num.size(); i++)
    {
        int max = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (num[j].first + 1 == num[i].first)
            {
                int index = 0, count = 0;
                for (int k = 0; k < num[i].first; k++)
                {
                    if (num[i].second[k] == num[j].second[index])
                    {
                        count++;
                        index++;
                    }
                }

                if (count == num[j].first)
                    max = std::max(max, storage[j]);
            }
        }

        storage[i] = 1 + max;
        result = std::max(result, storage[i]);
    }

    std::cout << result;
}
