class Solution {
public:
    int bitwiseComplement(int n) {
        int op = 1;
        while(op < n)
        {
            op = (op << 1) | 1;
        }
        int res = n ^ op;
        return res;
    }
};