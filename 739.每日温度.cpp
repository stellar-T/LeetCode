class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        int size = T.size();
        stack<int> st;
        vector<int> ans(size);
        st.push(0);
        for (int i = 0; i < size; i++)
        {
            if (T[i] <= T[st.top()])
                st.push(i);
            else
            {
                while (!st.empty() && T[i] > T[st.top()])
                {
                    ans[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        while (!st.empty())
        {
            ans[st.top()] = 0;
            st.pop();
        }
        return ans;
    }
};