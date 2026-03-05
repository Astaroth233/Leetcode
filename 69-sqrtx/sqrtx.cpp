class Solution {
public:
    int mySqrt(int x) {
        int start = 0, end = x;
        int res = 0;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(pow(mid, 2) > x)
            {
                end = mid - 1;
            }
            else if(pow(mid, 2) < x)
            {
                start = mid + 1;
                res = mid;
            }
            else
            {
                return mid;
            }
        }
        return res;
    }
};