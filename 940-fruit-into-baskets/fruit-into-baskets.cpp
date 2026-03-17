class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0, high = 0;
        int res = INT_MIN;
        int len;
        map<int,int> freq;
        for(high = 0; high<fruits.size();high++)
        {
            freq[fruits[high]] ++;
            while(freq.size() > 2)
            {
                freq[fruits[low]] --;
                if(freq[fruits[low]] == 0)
                {
                    freq.erase(fruits[low]);
                }
                low ++;
            }
            len = high - low + 1;
            res = max(res, len);

        }
        return res;
    }
};