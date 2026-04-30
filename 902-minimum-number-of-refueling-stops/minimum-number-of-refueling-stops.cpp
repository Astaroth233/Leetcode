class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        if(target <= startFuel)
        {
            return 0;
        }

        priority_queue<int> pq;

        sort(stations.begin(), stations.end());
        int w = startFuel;
        int idx = 0;
        int count = 0;

        while(true)
        {
            while(idx < stations.size())
            {
                if(stations[idx][0] > w)
                {
                    break;
                }
                pq.push(stations[idx][1]);
                idx++;
            }
            if(pq.empty())
            {
                if(w >= target)
                    return count;
                return -1;
            }
            w = w + pq.top();
            pq.pop();
            count ++;

            if(w >= target)
            {
                return count;
            }
        }
        return w >= target ? count : -1;
    }
};