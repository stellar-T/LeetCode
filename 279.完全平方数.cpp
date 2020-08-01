/*
    DP解法
状态转移方程 dp[i] = min(dp[i], dp[i - Res[j]] + 1)
计算这个结果前，前面的已经知道了，那么n减去一个任意完全平方数的结果+1的最小值，即是结果
*/
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, n);
        int MaxNum = (int)sqrt(n);
        vector<int> Res(MaxNum);
        for (int i = 1; i <= MaxNum; i++)
            Res[i - 1] = i * i;
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < MaxNum; j++)
            {
                if (i < Res[j])
                    break;
                dp[i] = min(dp[i], dp[i - Res[j]] + 1);
            }
        }
        return dp[n];
    }
};
/*
    BFS
    逐层向下
*/
class Solution
{
public:
    int numSquares(int n)
    {
        unordered_set<int> IsSqare;
        int MaxNum = (int)sqrt(n);
        int cot = 1;
        vector<int> Res(MaxNum);
        queue<int> qu;
        for (int i = 1; i <= MaxNum; i++)
        {
            Res[i - 1] = i * i;
            IsSqare.insert(Res[i - 1]);
        }
        qu.push(n);
        while (!qu.empty())
        {
            int size = qu.size();
            for (int i = 0; i < size; i++)
            {
                int num = qu.front();
                qu.pop();
                if (IsSqare.count(num))
                    return cot;
                for (int j = 1; j <= MaxNum; j++)
                    if (num < Res[j - 1])
                        break;
                    else
                        qu.push(num - Res[j - 1]);
            }
            cot++;
        }
        return cot;
    }
};