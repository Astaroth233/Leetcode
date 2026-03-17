class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int minlen = INT_MAX;
        int low = 0;
        int high = 0;
        for(high = 0;high<nums.size();high++)
        {
            sum = sum + nums[high];
            while(sum >= target)
            {
                int len = high - low + 1;
                minlen = min(minlen, len);
                sum = sum - nums[low];
                low++;
            }
            
        }
        return (minlen == INT_MAX)?0:minlen;
    }
};