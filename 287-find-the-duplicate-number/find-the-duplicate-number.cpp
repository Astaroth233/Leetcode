class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> m;
        for(int i:nums)
        {
            m[i] += 1;
            if(m[i] > 1)
            {
                return i;
            }
        }
        return -1;
    }
};