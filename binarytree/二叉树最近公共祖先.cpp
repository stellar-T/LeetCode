//递归法
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || root == p || root == q)
            return root;
        TreeNode *lright = lowestCommonAncestor(root->right, p, q);
        TreeNode *lleft = lowestCommonAncestor(root->left, p, q);
        if (lright && lleft)
            return root;
        if (!lleft)
            return lright;
        else
            return lleft;
        return NULL;
    }
};
//递归2
class Solution
{
public:
    TreeNode *ans = NULL;
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || ans)
            return false;
        bool r = dfs(root->right, p, q), l = dfs(root->left, p, q);
        if (root == p || root == q)
        {
            if (l || r)
                ans = root;
            return true;
        }

        if (r && l)
        {
            ans = root;
            return false;
        }
        return r || l;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        dfs(root, p, q);
        return ans;
    }
};