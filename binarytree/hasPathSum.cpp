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
//递归法
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if(!root->left&&!root->right)
            if(root->val==sum)
                return true;
            else
                return false;   
        return  root->left && hasPathSum(root->left, sum - root->val) || root->right && hasPathSum(root->right, sum - root->val);
    }
};
//BFS
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {   
        if(!root)
            return false;
        queue<int> asum;
        queue<TreeNode *> p;
        p.push(root);
        asum.push(root->val);
        while(!p.empty())
        {
            root = p.front();
            p.pop();
            if(!root->left&&!root->right)
            {
                if(sum==asum.front())
                    return true;
                asum.pop();
                continue;
            }
            if(root->left)
            {
                asum.push(root->left->val + asum.front());
                p.push(root->left);
            }
            if (root->right)
            {
                asum.push(root->right->val + asum.front());
                p.push(root->right);
            }
            asum.pop();
        }
    }
};
