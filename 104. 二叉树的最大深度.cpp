struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//bfs
class Solution
{
public:
    int max = 0;
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return max;
        queue<TreeNode *> qu;
        qu.push(root);
        while (!qu.empty())
        {
            int size = qu.size();
            for (int i = 0; i < size; i++)
            {
                root = qu.front();
                qu.pop();
                if (root->right)
                    qu.push(root->right);
                if (root->left)
                    qu.push(root->left);
            }
            max++;
        }
        return max;
    }
};
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
    int max(TreeNode *root, int a)
    {
        if (!root)
            return 0;
        if (a == cot)
            cot++;
        max(root->left, a + 1);
        max(root->right, a + 1);
        return 0;
    }
};