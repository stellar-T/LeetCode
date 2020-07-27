class Solution
{
public:
    unordered_map<int, int> mp;
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]] = i;
        for (int i = 0; i < nums.size(); i++)
            if (mp[target - nums[i]] && i != mp[target - nums[i]])
                return new vecor<int>({i, mp[target - nums[i]]});
    }
};