class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size() != s.size() || t.size() > s.size())
        {
            return false;
        }
        map<char, int> sm;
        map<char, int> tm;

        for(char c : s)
        {
            sm[c]++;
        } 
        for(char c : t)
        {
            tm[c] ++;
        }

        for(auto c : tm)
        {
            char letter = c.first;
            int ft = c.second;
            int st = sm[letter];
            if(st < ft)
            {
                return false;
            }
        }
        return true;
    }
    
};