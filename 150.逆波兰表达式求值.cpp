class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (string value : tokens)
        {
            int num;
            char t = value[0];
            switch (t)
            {
            case '+':
                num = st.top();
                st.pop();
                num = st.top() + num;
                st.pop();
                st.push(num);
                break;
            case '-':
                if (value.length() > 1)
                {
                    st.push(atoi(value.c_str()));
                    break;
                }
                num = st.top();
                st.pop();
                num = st.top() - num;
                st.pop();
                st.push(num);
                break;
            case '*':
                num = st.top();
                st.pop();
                num = st.top() * num;
                st.pop();
                st.push(num);
                break;
            case '/':
                num = st.top();
                st.pop();
                num = st.top() / num;
                st.pop();
                st.push(num);
                break;
            default:
                st.push(atoi(value.c_str()));
            }
        }
        return st.top();
    }
};
