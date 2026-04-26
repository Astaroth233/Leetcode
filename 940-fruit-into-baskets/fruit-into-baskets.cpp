class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int low = 0;
        int res = INT_MIN;
        for(int high = 0; high < fruits.size(); high++)
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

            if(freq.size() <= 2)
            {
                int len = high - low + 1;
                res = max(res, len);
            }
        }
        return res == INT_MIN ? -1 : res;
    }
};