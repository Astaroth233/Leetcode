class Solution {
public:
    int addDigits(int num) {
        int slow = num;
        while(slow > 9)
        {
            int sum = s(slow);
            slow = sum;
        }
        return slow;
    }

    int s(int num)
    {
        int sum = 0;
        while(num > 0)
        {
            int rem = num % 10;
            num = num / 10;
            sum += rem;
        }
        return sum;
    }

};