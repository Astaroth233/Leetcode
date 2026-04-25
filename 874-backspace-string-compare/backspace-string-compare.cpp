class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string anss = "";
        string anst = "";

        for(char ch : s)
        {
            if(ch == '#')
            {
                if(anss.size() > 0)
                {
                    anss.pop_back();
                }
            }
            else
            {
                anss += ch;
            }
        }

        for(char ch : t)
        {
            if(ch == '#')
            {
                if(anst.size() > 0)
                {
                    anst.pop_back();
                }
            }
            else
            {
                anst += ch;
            }
        }

        return anss == anst;
    }
};