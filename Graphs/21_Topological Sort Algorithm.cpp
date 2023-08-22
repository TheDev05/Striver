#include <bits/stdc++.h>
using namespace std;

void traverse(std::vector<int> num[], std::vector<int> &vis, std::stack<int> &st, int index)
{
    vis[index] = 1;
    for (auto i : num[index])
    {
        if (vis[i] == 0)
            traverse(num, vis, st, i);
    }

    st.push(index);
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> num[n];
    for (int i = 0; i < n; i++)
    {
        int m;
        std::cin >> m;

        std::vector<int> temp(m);
        for (auto &j : temp)
            std::cin >> j;

        num[i] = temp;
    }

    std::vector<int> vis(n, 0);
    std::stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
            traverse(num, vis, st, i);
    }

    std::vector<int> result;
    while (st.size())
    {
        result.push_back(st.top());
        st.pop();
    }

    for (auto i : result)
        std::cout << i << " ";
}