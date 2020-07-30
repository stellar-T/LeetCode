class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1->val && !l1->next)
            return l2;
        if (!l2->val && !l2->next)
            return l1;
        ListNode *l3 = NULL, *ans;
        int add = 0;
        while (l1 && l2)
        {
            int res = l1->val + l2->val + add;
            add = res / 10;
            ListNode *s = new ListNode(res - add * 10);
            l1 = l1->next;
            l2 = l2->next;
            if (!l3)
                ans = s;
            else
                l3->next = s;
            l3 = s;
        }
        while (l1)
        {
            int res = l1->val + add;
            add = res / 10;
            ListNode *s = new ListNode(res - add * 10);
            l1 = l1->next;
            l3->next = s;
            l3 = s;
        }
        while (l2)
        {
            int res = l2->val + add;
            add = res / 10;
            ListNode *s = new ListNode(res - add * 10);
            l2 = l2->next;
            l3->next = s;
            l3 = s;
        }
        if (add)
        {
            ListNode *s = new ListNode(add);
            l3->next = s;
            l3 = s;
        }
        return ans;
    }
};
