class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;

        for(int i=0;i<piles.size();i++)
        {
            high = max(high, piles[i]);
        }

        int res = 0;

        while(low <= high)
        {
            int val = low + (high - low) / 2;
            long long ans = kokohelp(piles, h, val);

            if(ans <= h)
            {
                res = val;
                high = val - 1;
            }
            else
            {
                low = val + 1;
            }
        }
        return res;
    }

    long long kokohelp(vector<int> &piles, int h, int val)
    {
        long long res = 0;
        for(int i=0;i<piles.size();i++)
        {
            res += (piles[i] / val);
            if((piles[i]%val) != 0)
            {
                res += 1;
            }
        }
        return res;
    }
};