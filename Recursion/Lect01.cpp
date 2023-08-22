#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void printCount()
{
    if (cnt == 4)
    {
        return;
    }

    std::cout << cnt << '\n';
    cnt++;

    printCount();
}

int main()
{
    printCount();
}

// 1. Recurrsion
// 2. Base Cases
// 3. Stack Spaces & Stack Overflow
// 4. Recurrsion Tree