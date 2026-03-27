class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        while(true)
        {
            slow = square(slow);
            fast = square(fast);
            fast = square(fast);
            if(slow == fast)
            {
                break;
            }
        }
        return slow == 1;
    }

    int square(int n)
    {
        int sum = 0;
        while(n > 0)
        {
            int d = n % 10;
            n = n / 10;
            sum += (d * d);
        }
        return sum;
    }
};