class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int count = 0;
        int sum = 0;
        int rem = 0;

        for(int i : nums)
        {
            sum += i;
            rem = sum - k;

            count += m[rem];
            m[sum]++;
        }
        return count;
    }
};