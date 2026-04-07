class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        f[0] = 1;
        int res = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            int rem = sum - k;
            int freq = f[rem];
            res += freq;
            f[sum] ++;
        }
        return res;
    }
};