class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }
            int curr = -1 * nums[i];
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right)
            {
                int sum = nums[left] + nums[right];
                if(sum == curr)
                {
                    res.push_back({-1 * curr, nums[left], nums[right]});
                    left ++;
                    right --;

                    while(left < nums.size() && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                    while(right >= 0 && nums[right] == nums[right + 1])
                    {
                        right --;
                    }
                }
                else if(sum > curr)
                {
                    right --;
                }
                else
                {
                    left ++;
                }
            }
        }
        return res;
    }
};