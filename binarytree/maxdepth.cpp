#include <vector>
#include <stack>
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//bfs
int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;
    queue<TreeNode *> qu;
    qu.push(root);
    int size = qu.size(),cot=0;
    while (!qu.empty())
    {
        vector<int> a;
        for (int i = 0; i < size; i++)
        {
            root = qu.front();
            qu.pop();
            if (root->left)
                qu.push(root->left);
            if (root->right)
                qu.push(root->right);
        }
        size = qu.size();
        cot++;
    }
    return cot;
}
//递归
class Solution
{
public:        
    int cot;
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        cot = 0;
        max(root, cot);
        return cot;
    }
    int max(TreeNode *root,int a)
    {
        if (!root)
            return 0;
        if(a==cot)
            cot++;
        max(root->left, a + 1);
        max(root->right, a + 1);
        return 0;
    }
};