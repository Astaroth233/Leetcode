class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size())
        {
            return "";
        }

        vector<int> tmap(256, 0), smap(256, 0);
        for(char ch : t)
        {
            tmap[ch] ++;
        }

        int low = 0, count = 0;
        int start =0, res = INT_MAX;

        for(int high = 0; high < s.size(); high ++)
        {
            smap[s[high]] ++;
            if(smap[s[high]] <= tmap[s[high]])
            {
                count ++;
            }
            while(count == t.size())
            {
                int len = high - low + 1;
                if(len < res)
                {
                    res = len;
                    start = low;
                }
                smap[s[low]] --;
                if(smap[s[low]] < tmap[s[low]])
                {
                    count --;
                }
                low ++;
            }
        }
        if(res == INT_MAX)
        {
            return "";
        }
        return s.substr(start, res);
    }
};