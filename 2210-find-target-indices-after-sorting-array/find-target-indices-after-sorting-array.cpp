class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less = 0;
        int found = 0;

        for(int i : nums)
        {
            if(i == target){
                found ++;
            }
            else if(i < target)
            {
                less ++;
            }
        }

        vector<int> res;
        for(int i=0;i<found;i++)
        {
            res.push_back(less + i);
        }
        return res;
    }
};