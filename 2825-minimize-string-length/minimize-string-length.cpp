class Solution {
public:
    int minimizedStringLength(string s) {
        vector<int> store(26, 0);

        for(char ch : s)
        {
            if(store[ch-'a'] == 0)
            {
                store[ch-'a'] = 1;
            }
        }

        int count = 0;
        for(int i : store)
        {
            if(i == 1)
            {
                count ++;
            }
        }
        return count;
    }
};