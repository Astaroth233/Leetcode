class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string ans = "";
        gPhelper(n, 0, 0, res, ans);
        return res;
    }

    void gPhelper(int n, int open, int close, vector<string> &res, string ans)
    {
        if(open == n && close == n)
        {
            res.push_back(ans);
            return;
        }

        if(open < n)
        {
            ans.push_back('(');
            gPhelper(n, open + 1, close, res, ans);
            ans.pop_back();
        }
        if(open > close)
        {
            ans.push_back(')');
            gPhelper(n, open, close + 1, res, ans);
            ans.pop_back();
        }
        return;
    }
};