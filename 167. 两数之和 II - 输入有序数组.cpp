//双指针法
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int index1=1;
        int index2=nums.size();
        while(nums[index1-1]+nums[index2-1]!=target)
        {
            nums[index1-1]+nums[index2-1]>target?index2--:index1++;
        }
        return *new vector<int>({index1,index2});
    }
};