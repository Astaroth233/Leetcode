class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }
            int val = -1 * nums[i];
            int l = i + 1, h = nums.size()-1;

            while(l < h)
            {
                int sum = nums[l] + nums[h];
                if(sum == val)
                {
                    res.push_back({nums[i], nums[l], nums[h]});
                    l++;
                    h--;

                    while(l<nums.size() && nums[l] == nums[l-1])
                    {
                        l++;
                    }

                    while(h>=0 && nums[h] == nums[h+1])
                    {
                        h--;
                    }
                }
                else if(sum > val)
                {
                    h --;
                }
                else
                {
                    l ++;
                }
            }
        }
        return res;
    }
};