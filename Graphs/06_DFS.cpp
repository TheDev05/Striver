#include <bits/stdc++.h>
using namespace std;

void traverse(std::vector<int> num[], int vertex, std::vector<int> &visited, std::vector<int> &result)
{
    result.push_back(vertex);
    visited[vertex] = 1;

    for (auto i : num[vertex])
    {
        if (!visited[i])
            traverse(num, i, visited, result);
    }
}

int main()
{
    int v;
    std::cin >> v;

    std::vector<int> num[v];

    num[0].push_back(1);
    num[0].push_back(2);

    std::vector<int> visited(v, 0);
    std::vector<int> result;

    traverse(num, 0, visited, result);

    for (auto i : result)
        std::cout << i << " ";
}