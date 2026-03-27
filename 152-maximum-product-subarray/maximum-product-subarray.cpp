class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minSum = nums[0];
        int maxSum = nums[0];
        int res = nums[0];

        for(int i=1;i<nums.size();i++)
        {
            int v1 = nums[i] * minSum;
            int v2 = nums[i] * maxSum;
            int v3 = nums[i];
            minSum = min(v1, min(v2, v3));
            maxSum = max(v1, max(v2, v3));
            res = max(res, max(minSum, maxSum));
        }
        return res;
    }
};