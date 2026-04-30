class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string ans = "";
        vector<string> res;

        generate(n, res, 0, 0, ans);
        return res;        
    }

    void generate(int n, vector<string> &res, int open, int close, string &ans)
    {
        if(open == n && close == n)
        {
            res.push_back(ans);
            return;
        }

        if(open < n)
        {
            ans.push_back('(');
            generate(n,res,open+1,close,ans);
            ans.pop_back();
        }
        if(close < open)
        {
            ans.push_back(')');
            generate(n,res,open,close+1,ans);
            ans.pop_back();
        }
        return;
    }
};