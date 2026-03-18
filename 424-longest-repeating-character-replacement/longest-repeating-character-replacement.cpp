class Solution {
public:
    int characterReplacement(string s, int k) {
        int low = 0;
        vector<int> freq(26, 0);
        int maxlen = 0;
        int maxcount = 0;
        for(int high=0; high<s.size(); high++)
        {
            freq[s[high] - 'A']++;
            maxcount = max(maxcount, freq[s[high] - 'A']);
            while((high - low + 1) - maxcount > k)
            {
                freq[s[low] - 'A']--;
                low++;
            }
            maxlen = max(maxlen, high-low+1);
        }
        return maxlen;
    }
};