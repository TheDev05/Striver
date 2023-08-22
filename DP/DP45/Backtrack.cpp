#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<std::pair<int, std::string>> &num, std::map<std::pair<int, std::string>, int> &storage, std::string &temp, int index)
{
    if (index >= num.size())
        return 0;

    if (storage.count({index, temp}) == false)
    {
        bool ok = false;
        if (temp.empty() || num[index].first - 1 == temp.size())
        {
            int j = 0, count = 0;
            for (int i = 0; i < num[index].first; i++)
            {
                if (num[index].second[i] == temp[j])
                {
                    count++;
                    j++;
                }
            }

            if (j == temp.size())
                ok = true;
        }

        int val1 = 0, val2 = 0;
        if (ok)
            val1 = 1 + getCount(num, storage, num[index].second, index + 1);
        val2 = getCount(num, storage, temp, index + 1);

        storage[{index, temp}] = std::max(val1, val2);
    }

    return storage[{index, temp}];
}

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

    std::string temp;

    std::map<std::pair<int, std::string>, int> storage;
    std::cout << getCount(num, storage, temp, 0);
}
