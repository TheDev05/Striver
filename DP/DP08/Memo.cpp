#include <bits/stdc++.h>
using namespace std;

int getPaths(std::vector<std::vector<int>> &storage, int i, int j)
{
    if (i >= storage.size() || j >= storage[0].size())
        return 0;
    if (i == storage.size() - 1 && j == storage[0].size() - 1)
        return 1;

    if (storage[i][j] == -1)
    {
        int right = getPaths(storage, i, j + 1);
        int down = getPaths(storage, i + 1, j);

        storage[i][j] = right + down;
    }

    return storage[i][j];
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> storage(n, std::vector<int>(m, -1));
    std::cout << getPaths(storage, 0, 0);
}