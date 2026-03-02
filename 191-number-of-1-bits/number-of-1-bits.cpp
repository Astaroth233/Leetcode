class Solution {
public:
    int hammingWeight(int n) {
        int c = 0;
        while(n > 0)
        {
            int lastDig = n & 1;
            c += lastDig;
            n = n >> 1;
        }
        return c;
    }
};