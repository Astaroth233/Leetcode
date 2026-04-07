class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        unordered_map<int, int> f;
        int z=0;
        int o=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0)
            {
                z ++;
            }
            else
            {
                o ++;
            }
            int diff = z - o;
            if(diff == 0)
            {
                res= max(res, i+1);
                continue;
            }
            if(f.find(diff) == f.end())
            {
                f[diff] = i;
            }
            else
            {
                int idx = f[diff];
                int len = i - idx;
                res = max(res, len);
            }
        }
        return res;
    }
};