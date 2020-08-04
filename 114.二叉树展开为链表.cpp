//非原地展开（不合题意
class Solution
{
public:
    TreeNode *ans;
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        ans = new TreeNode(root->val);
        TreeNode *a = ans;
        if (root->left)
            dfs(root->left);
        if (root->right)
            dfs(root->right);
        root->right = a->right;
        root->left = nullptr;
    }
    void dfs(TreeNode *tree)
    {
        ans->right = new TreeNode(tree->val);
        ans = ans->right;
        if (tree->left)
            dfs(tree->left);
        if (tree->right)
            dfs(tree->right);
    }
};
//dfs
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        dfs(root);
    }
    TreeNode *dfs(TreeNode *root)
    {
        if (!root)
            return root;
        TreeNode *right, *left, *cur = root;
        left = dfs(root->left);
        right = dfs(root->right);
        root->right = left;
        root->left = nullptr;
        while (root->right)
        {
            root = root->right;
        }
        root->right = right;
        return cur;
    }
};