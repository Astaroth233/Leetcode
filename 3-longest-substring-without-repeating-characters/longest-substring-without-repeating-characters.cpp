class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "")
        {
            return 0;
        }
        unordered_map<int, int> f;

        int low = 0;
        int res = INT_MIN;

        for(int high = 0; high < s.size(); high ++)
        {
            f[s[high]] ++;
            int winlen = high - low + 1;
            while(f.size() < winlen)
            {
                f[s[low]] --;
                if(f[s[low]] == 0)
                {
                    f.erase(s[low]);
                }
                low ++;
                winlen = high - low + 1;
            }
            int len = high - low + 1;
            res = max(res, len);
        }
        return res == INT_MIN ? -1 : res;
    }
};