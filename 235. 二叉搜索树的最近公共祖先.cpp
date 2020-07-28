//递归
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *left, *right;
        if (!root)
            return NULL;
        if (root == p || root == q)
            return root;
        left = lowestCommonAncestor(root->left, p, q);
        right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;
        if (left && !right)
            return left;
        if (!left && right)
            return right;
        return NULL;
    }
};
//迭代法
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while (root)
        {
            if ((root->val > p->val && root->val < q->val) || (root->val < p->val && root->val > q->val) || p == root || q == root)
                return root;
            if (!root->left || root->val < p->val && root->val < q->val)
                root = root->right;
            else
                root = root->left;
        }
        return root;
    }
};