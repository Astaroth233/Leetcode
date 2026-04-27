class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minSum = nums[0], maxSum = nums[0];
        int res = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int v1 = nums[i];
            int v2 = nums[i] + maxSum;
            int v3 = nums[i] + minSum;
            // minSum = abs(min(v1, min(v2, v3)));
            maxSum = max(v1, v2);
            minSum = min(v1, v3);
            res = max(res, max(abs(maxSum), abs(minSum)));
        }
        return abs(res);
    }
};