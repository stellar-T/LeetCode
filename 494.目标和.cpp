//递归暴力解法 O(2^n)
class Solution
{
public:
    int size;
    int ans = 0;
    int findTargetSumWays(vector<int> &nums, int S)
    {
        size = nums.size();
        dfs(nums, 0, 0, 0, S);
        dfs(nums, 0, 0, 1, S);
        return ans;
    }
    void dfs(vector<int> &nums, int num, int i, int op, int s)
    {
        if (i == size)
        {
            if (num == s && op)
                ans++;
            return;
        }
        if (op == 0)
            num = num - nums[i];
        else
            num = num + nums[i];
        dfs(nums, num, i + 1, 0, s);
        dfs(nums, num, i + 1, 1, s);
    }
};
//回溯法
class Solution
{
public:
    int size;
    int ans = 0;
    int findTargetSumWays(vector<int> &nums, int S)
    {
        size = nums.size();
        track(nums, 0, S);
        return ans;
    }
    void track(vector<int> &nums, int i, long S)
    {
        if (i == size)
        {
            if (!S)
                ans++;
            return;
        }
        S -= nums[i];
        track(nums, i + 1, S);
        S += 2 * nums[i];
        track(nums, i + 1, S);
        S -= nums[i];
    }
};
//  DP
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        if (S > 1000)
            return 0;
        vector<int> mp(4002, 0);
        int size = nums.size();
        mp[nums[0] + 1000] = 1;
        mp[-nums[0] + 1000] += 1;
        for (int i = 1; i < size; i++)
        {
            int k = i & 1;
            int l = k ^ 1;
            for (int j = -1000; j <= 1000; j++)
                mp[j + k * 2001 + 1000] = 0;
            for (int j = -1000; j <= 1000; j++)
            {  
                if (!mp[j + l * 2001 + 1000])
                    continue;
                mp[j - nums[i] + k * 2001 + 1000] += mp[j + l * 2001 + 1000];
                mp[j + nums[i] + k * 2001 + 1000] += mp[j + l * 2001 + 1000];
            }
        }

        int k = size & 1 ^ 1;
        return mp[S + k * 2001 + 1000];
    }
};