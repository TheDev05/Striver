#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v;
    std::cin >> v;

    std::vector<int> num[v];

    num[0].push_back(1);
    num[0].push_back(2);

    int startNode = 0;

    std::queue<int> inox;
    std::vector<int> visited(v, 0);

    inox.push(startNode);
    visited[startNode] = 1;

    std::vector<int> result;
    while (inox.size())
    {
        int temp = inox.front();
        inox.pop();

        for (auto i : num[temp])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                inox.push(i);
            }
        }

        result.push_back(temp);
    }

    for (auto i : result)
        std::cout << i << " ";

    // space: O(nodes)
    // Time: O(nodes*(all degress)) or O(nodes*(2E))
}