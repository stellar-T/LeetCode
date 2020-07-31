class Solution
{
public:
    int NotSeach = 0, Searched = 1, Locked = 2;
    unordered_set<string> deadEnds;
    unordered_set<string> visited;
    queue<string> qu;
    int openLock(vector<string> &deadends, string target)
    {
        for (auto &dead : deadends)
            deadEnds.insert(dead);
        if (deadEnds.count("0000"))
            return -1;
        qu.push("0000");
        visited.insert("0000");
        int cot = 0;
        while (!qu.empty())
        {
            int n = qu.size();
            for (int i = 0; i < n; i++)
            {
                string s = qu.front();
                qu.pop();
                if (deadEnds.count(s))
                    continue;
                if (s == target)
                    return cot;
                for (int j = 0; j < 4; j++)
                {
                    string h = add(s, j);
                    if (!visited.count(h))
                    {
                        qu.push(h);
                        visited.insert(h);
                    }
                    string g = de(s, j);
                    if (!visited.count(g))
                    {
                        qu.push(g);
                        visited.insert(g);
                    }
                }
            }
            cot++;
        }
        return -1;
    }
    string add(string s, int n)
    {
        if (s[n] == '9')
            s[n] = '0';
        else
            s[n] += 1;
        return s;
    }
    string de(string s, int n)
    {
        if (s[n] == '0')
            s[n] = '9';
        else
            s[n] -= 1;
        return s;
    }
};