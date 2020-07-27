#include <vector>
#include <stack>
#include <iostream>
#include <queue>
struct Node {
   int val;
  Node *left;
  Node *right;
  Node *next;
}

class Solution
{
public:
    queue<Node *> qu;
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        Node *p = root;
        qu.push(p);
        while (!qu.empty())
        {
            int size = qu.size();
            for (int i = 1; i <= size; i++)
            {
                p = qu.front();
                qu.pop();
                if (p->left)
                    qu.push(p->left);
                if (p->right)
                    qu.push(p->right);
                if (size != i)
                    p->next = qu.front();
                else
                    p->next = NULL;
            }
        }
        return root;
    }
};