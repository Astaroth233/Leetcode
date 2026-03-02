class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int c = 1;
        sort(nums.begin(), nums.end());
        int curr = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == curr)
            {
                c ++;
            }
            else
            {
                if(c == 1)
                {
                    return curr;
                }
                else
                {
                    c = 1;
                    curr = nums[i];
                }
            }
        }
        if(c == 1)
        {
            return curr;
        }
        return -1;
    }
};