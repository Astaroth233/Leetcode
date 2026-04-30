class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
        {
            return {};
        }
        unordered_map<char, string> p;

        p['2'] = "abc";
        p['3'] = "def";
        p['4'] = "ghi";
        p['5'] = "jkl";
        p['6'] = "mno";
        p['7'] = "pqrs";
        p['8'] = "tuv";
        p['9'] = "wxyz";

        vector<string> res;
        func(digits, digits.size(), 0, "", res, p);
        return res;
    }

    void func(string &s, int n, int idx, string diary, vector<string> &res, unordered_map<char, string> p)
    {
        if(idx == n)
        {
            res.push_back(diary);
            return;
        }

        string choice = p[s[idx]];

        for(int i=0;i<choice.size();i++)
        {
            diary.push_back(choice[i]);
            func(s,n,idx+1,diary,res, p);
            diary.pop_back();
        }
    }
};