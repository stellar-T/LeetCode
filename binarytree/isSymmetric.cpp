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
class Solution
{
    public:
        bool isSymmetric(TreeNode *root)
        {
            return ismirron(root, root);
        }
        bool ismirron(TreeNode*p1,TreeNode* p2)
        {
            if(p1==NULL&&p2==NULL)
                return true;
            if(p1==NULL||p2==NULL)
                return false;
            return (p1 == p2 && ismirron(p1->left, p2->right) && ismirron(p2->left, p1->right));
        }
};
