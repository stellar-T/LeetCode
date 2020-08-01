class Solution
{
public:
    stack<char> st;
    bool isValid(string s)
    {
        int size = s.size();
        if (size & 1)
            return false;
        unordered_map<char, char> mp{{']', '['}, {'}', '{'}, {')', '('}};
        for (int i = 0; i < size; i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else if (st.empty() || st.top() != mp[s[i]])
                return false;
            else
                st.pop();
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};