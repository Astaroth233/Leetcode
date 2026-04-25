class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        vector<int> res(nums.size(), 0);

        for(int i : nums)
        {
            if(i >= 0)
                pos.push_back(i);
            else
                neg.push_back(i);
        }

        // square negatives
        for(int i = 0; i < neg.size(); i++)
            neg[i] = neg[i] * neg[i];

        // reverse negatives to make sorted
        reverse(neg.begin(), neg.end());

        // square positives
        for(int i = 0; i < pos.size(); i++)
            pos[i] = pos[i] * pos[i];

        // merge
        int i = 0, j = 0, idx = 0;
        while(i < pos.size() && j < neg.size())
        {
            if(pos[i] <= neg[j])
                res[idx++] = pos[i++];
            else
                res[idx++] = neg[j++];
        }

        while(i < pos.size())
            res[idx++] = pos[i++];

        while(j < neg.size())
            res[idx++] = neg[j++];

        return res;
    }
};