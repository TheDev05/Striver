#include <bits/stdc++.h>
using namespace std;

set<vector<int>> data;
void getSet(vector<int> num, vector<int> temp, vector<vector<int>> *res, int index)
{
    if (index >= num.size())
    {
        sort(temp.begin(), temp.end());
        if (data.count(temp) == false)
        {
            res->push_back(temp);
            data.insert(temp);
        }

        return;
    }

    temp.push_back(num[index]);
    getSet(num, temp, res, index + 1);

    temp.pop_back();
    getSet(num, temp, res, index + 1);
}

int main()
{
    vector<int> num, temp;
    vector<vector<int>> res;

    num.push_back(1);
    num.push_back(2);
    num.push_back(2);

    set<vector<int>> data;
    getSet(num, temp, &res, 0);

    cout << res.size();
    // return (res);
}