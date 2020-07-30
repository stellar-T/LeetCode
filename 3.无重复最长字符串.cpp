class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> map(128, -1);
        int len = 0, start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (map[s[i]] >= start)
                start = map[s[i]] + 1;
            map[s[i]] = i;
            len = max(len, i - start + 1);
        }
        return len;
    }
};
