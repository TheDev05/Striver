#include <bits/stdc++.h>
using namespace std;

void dfs(std::vector<std::vector<int>> &adj, std::vector<int> &vis, std::stack<int> &st, int index)
{
    vis[index] = 1;
    for (auto i : adj[index])
    {
        if (vis[i] == 0)
            dfs(adj, vis, st, i);
    }

    st.push(index);
}

void dfs2(std::vector<int> num[], std::vector<int> &vis, int index)
{
    vis[index] = 1;
    for (auto i : num[index])
    {
        if (vis[i] == 0)
            dfs2(num, vis, i);
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj;
    for (int i = 0; i < n; i++)
    {
        int m;
        std::cin >> m;

        std::vector<int> temp(m);
        for (auto &j : temp)
            std::cin >> j;

        adj.push_back(temp);
    }

    std::vector<int> vis(n, 0);
    std::stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
            dfs(adj, vis, st, i);
    }

    std::vector<int> num[n];
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            num[it].push_back(i);
        }
    }

    vis.clear();
    std::set<int> inox;

    int count = 0;
    while (st.size())
    {
        int val = st.top();
        st.pop();

        if (vis[val] == 0)
        {
            count++;
            dfs2(num, vis, val);
        }
    }

    std::cout << count;
}