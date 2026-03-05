class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 0, end = num;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(pow(mid, 2) > num)
            {
                end = mid - 1;
            }
            else if(mid * mid < num)
            {
                start = mid + 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};