class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > bloomDay.size())
        {
            return -1;
        }
        int low = 1, high = 0;
        int res = 0;
        for(int i=0;i<bloomDay.size();i++)
        {
            high = max(high, bloomDay[i]);
        }

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(bloom(bloomDay, k, mid) >= m)
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res == 0 ? -1 : res;
    }

    int bloom(vector<int> &a, int k, int day)
    {
        int res = 0;
        int v = k;
        for(int i=0;i<a.size();i++)
        {
            if(a[i] <= day)
            {
                v --;
            }
            else
            {
                v = k;
            }
            if(v == 0)
            {
                res ++;
                v = k;
            }
        }
        return res;
    }
};