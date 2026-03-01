class Solution {
public:
    string reverseVowels(string s) 
    {
        string vowels = "AEIOUaeiou";
        int n = s.length();
        int start = 0;
        int end = n - 1;
        while(start < end)
        {
            if(findvow(s[start],vowels) && findvow(s[end], vowels))
            {
                swap(s[start], s[end]);
                start++;
                end--;
            }
            else if(!(findvow(s[start], vowels)) && findvow(s[end], vowels))
            {
                start ++;
            }
            else if(findvow(s[start],vowels) && !(findvow(s[end], vowels)))
            {
                end --;
            }
            else
            {
                start ++;
                end --;
            }
        }
        return s;
    }

    bool findvow(char ch, string vowels)
    {
        for(char c:vowels)
        {
            if(c == ch)
            {
                return true;
            }
        }
        return false;
    }
};