class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_map<char, int> map;

        for(char ch : s)
        {
            if(map.find(ch) == map.end())
            {
                map[ch] ++;
            }
        }
        return map.size();
    }
};