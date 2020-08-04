//递归
class Solution
{
public:
    string decodeString(string s)
    {
        string ans;
        int ptr = 0, l = 0;
        for (ptr = 0; ptr < s.length(); ptr++)
        {
            if (isdigit(s[ptr]))
            {
                int n = s[ptr] - '0';
                ptr++;
                while (isdigit(s[ptr]))
                {
                    n = n * 10 + s[ptr] - '0';
                    ptr++;
                }
                string k;
                bool isword = true;
                for (; ptr < s.length(); ptr++)
                {
                    if (s[ptr] == '[')
                    {
                        l++;
                        if (l != 1)
                        {
                            k += '[';
                            isword = false;
                        }
                        continue;
                    }
                    else if (s[ptr] == ']')
                    {
                        l--;
                        if (l != 0)
                            k += ']';
                        else
                            break;
                        continue;
                    }
                    else
                        k += s[ptr];
                }
                while (n--)
                    if (isword)
                        ans += k;
                    else
                    {
                        ans += decodeString(k);
                    }
            }
            else
                ans += s[ptr];
        }
        return ans;
    }
};