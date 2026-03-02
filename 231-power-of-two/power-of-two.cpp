class Solution {
public:
    bool isPowerOfTwo(int n) {
        int c = 0;
        while(n > 0)
        {
            int lastDig = n & 1;
            c += lastDig;
            n = n >> 1;
        }
        if(c == 1) return true;
        return false; 
    }
};