class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> f;
        for(int i : nums)
        {
            if(f[i] == 1)
            {
                return true;
            }
            f[i] ++;
        }
        return false;
    }
};