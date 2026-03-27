class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<int> st;
        for(char ch : s)
        {
            st.push(ch);
        }

        int idx = 0;
        while(idx < s.size() && !(st.empty()))
        {
            s[idx++] = st.top();
            st.pop();
        }
    }
};