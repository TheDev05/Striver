#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int temp)
    {
        this->left = this->right = NULL;
        this->val = temp;
    }
};

std::map<int, int> inox;
TreeNode *traverse(std::vector<int> &in, int inStart, int inLast, std::vector<int> &post, int postStart, int postLast)
{
    if (inStart > inLast || postStart > postLast)
        return NULL;

    int rootIndex = inox[post[postLast]];
    TreeNode *root = new TreeNode(post[postLast]);

    root->left = traverse(in, inStart, rootIndex - 1, post, postStart, postLast - 1 - (inLast - rootIndex));
    root->right = traverse(in, rootIndex + 1, inLast, post, postLast - (inLast - rootIndex), postLast - 1);

    return root;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> in(n), post(n);
    for (auto &i : in)
        std::cin >> i;

    for (auto &i : post)
        std::cin >> i;

    for (int i = 0; i < post.size(); i++)
    {
        inox[in[i]] = i;
    }

    traverse(in, 0, in.size() - 1, post, 0, post.size() - 1);
}