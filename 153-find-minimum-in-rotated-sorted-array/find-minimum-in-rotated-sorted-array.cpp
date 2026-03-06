class Solution {
public:
    int findMin(vector<int>& nums) {

        int start = 0;
        int end = nums.size() - 1;

        while(start < end)
        {
            int mid = start + (end - start) / 2;

            if(nums[mid] > nums[end])
            {
                start = mid + 1;  // minimum in right part
            }
            else
            {
                end = mid;        // minimum in left part
            }
        }

        return nums[start];
    }
};