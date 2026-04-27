class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax = 0, maxSum = INT_MIN;
        int currMin = 0, minSum = INT_MAX;
        int totSum = 0;

        for(int i : nums)
        {
            totSum += i;

            currMax = max(i, currMax + i);
            maxSum = max(maxSum, currMax);

            currMin = min(i, currMin + i);
            minSum = min(minSum, currMin);
        }

        if(maxSum < 0)
        {
            return maxSum;
        }
        return max(maxSum, totSum - minSum);
    }
};