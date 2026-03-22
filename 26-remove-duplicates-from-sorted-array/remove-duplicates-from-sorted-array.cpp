class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        int curr = 1;
        int res = 1;
        while(curr < nums.size())
        {
            if(nums[curr] != nums[curr-1])
            {
                nums[++idx] = nums[curr++];
                res ++;
            }
            else
            {
                curr++;
            }
        }
        return res;
    }
};