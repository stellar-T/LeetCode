class Solution
{
public:
    vector<int> smallestRange(vector<vector<int> > &nums)
    {
        vector<pair<int, int> > ordered;
        for (int k = 0; k < nums.size(); ++k)
            for (auto n : nums[k])
                ordered.push_back({n, k});
        sort(ordered.begin(), ordered.end());
        int i = 0;
        vector<int> ans;
        unordered_map<int, int> count;
        int j = 0, k = 0;
        while (k != nums.size())
            if (!count[ordered[j++].second]++)
                ++k;
        while (count[ordered[i].second] > 1)
            --count[ordered[i++].second];
        ans = vector<int>{ordered[i].first, ordered[j - 1].first};
        for (; j < ordered.size(); ++j)
        {
            count[ordered[j].second]++;
            while (count[ordered[i].second] > 1)
                --count[ordered[i++].second];
            if (ans[1] - ans[0] > ordered[j].first - ordered[i].first)
            {
                ans = vector<int>{ordered[i].first, ordered[j].first};
            }
        }
        return ans;
    }
};
