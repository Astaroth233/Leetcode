class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = 0;
        int res = 0;
        for(int i : candies)
        {
            high = max(high, i);
        }

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            long long distr = candy(candies, k, mid);
            if(distr >= k)
            {
                res = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return res;
    }

    long long candy(vector<int> &candies, int k, int c)
    {
        long long res = 0;
        for(int i=0;i<candies.size();i++)
        {
            res += (candies[i] / c);
        }
        return res;
    }
};