class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int diff = INT_MAX;
        for(int i=0;i<nums.size()-2;i++)
        {
            int curr = nums[i];
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right)
            {
                int sum = nums[left] + nums[right] + curr;
                int val = abs(target - sum);
                if(val < diff)
                {
                    res = sum;
                    diff = val; 
                }
                if(sum == target)
                {
                    return res;
                }
                else if(sum < target)
                {
                    left ++;
                }
                else
                {
                    right --;
                }
            }
        }
        return res;
    }
};