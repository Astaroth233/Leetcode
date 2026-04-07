class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == n)
            {
                return true;
            }
            n = nums[i];
        }
        return false;
    }
};