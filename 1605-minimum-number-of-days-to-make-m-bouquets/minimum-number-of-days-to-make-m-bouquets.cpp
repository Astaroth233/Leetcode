class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL * m*k > bloomDay.size())
        {
            return -1;
        }
        int start = minimum(bloomDay), end = maximum(bloomDay);
        int ans = end;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(possible(bloomDay, mid, m, k))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }

    int maximum(vector<int>& num)
    {
        int val = INT_MIN;
        for(int i=0;i<num.size();i++)
        {
            if(num[i] > val)
            {
                val = num[i];
            }
        }
        return val;
    }

    int minimum(vector<int>& num)
    {
        int val = INT_MAX;
        for(int i=0;i<num.size();i++)
        {
            if(num[i] < val)
            {
                val = num[i];
            }
        }
        return val;
    }

    bool possible(vector<int>& arr, int day, int m, int k)
{
    int count = 0;
    int bouq = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] <= day)
        {
            count++;
            if(count == k)        // bouquet formed
            {
                bouq++;
                count = 0;

                if(bouq >= m)     // 🔥 early exit
                    return true;
            }
        }
        else
        {
            count = 0;
        }
    }

    return false;
}
};