class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low = 1; 
        int high = 0;
        for(int i=0;i<citations.size();i++)
        {
            high = max(high, citations[i]);
        }

        int h = 0;
        int n = citations.size();
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(Hhelp(citations, mid))
            {
                h = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return h;
    }

    bool Hhelp(vector<int> &arr, int h)
    {
        int count = 0;
        for(int x : arr)
        {
            if(x >= h) count++;
        }
        return count >= h;
    }
};