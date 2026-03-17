class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vec;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i > 0 and nums[i] == nums[i-1])
            {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            int sum = -1 * nums[i];
            while(left < right)
            {
                int s = nums[left] + nums[right];
                if(s == sum)
                {
                    vec.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < nums.size() && nums[left] == nums[left-1])
                    {
                        left++;
                    }
                    while(right >= 0 && nums[right] == nums[right + 1])
                    {
                        right --;
                    }
                }
                else if(s < sum)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return vec;
    }
};