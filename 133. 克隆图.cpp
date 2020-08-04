//DFS
class Solution
{
public:
    Node *ans;
    unordered_map<Node *, Node *> mp;
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        ans = new Node(0);
        dps(ans, node);
        return ans;
    }
    void dps(Node *ans, Node *node)
    {
        if (mp.count(node))
            return;
        ans->val = node->val;
        mp[node] = ans;
        for (auto p : node->neighbors)
        {
            Node *s;
            if (mp.count(p))
            {
                ans->neighbors.push_back(mp[p]);
                s = p;
            }
            else
            {
                s = new Node(0);
                s->val = p->val;
                ans->neighbors.push_back(s);
            }
            dps(s, p);
        }
    }
};