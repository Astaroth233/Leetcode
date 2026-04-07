class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size() != s.size() || t.size() > s.size())
        {
            return false;
        }
        unordered_map<char, int> sm;
        unordered_map<char, int> tm;

        for(char c : s)
        {
            sm[c]++;
        } 
        for(char c : t)
        {
            tm[c] ++;
        }

        return tm == sm;
    }
    
};