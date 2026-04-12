class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int s = startFuel;

        int n = stations.size();
        vector<pair<int, int>> refuel;
        for(int i=0;i<stations.size();i++)
        {
            refuel.push_back({stations[i][0], stations[i][1]});
        }

        sort(refuel.begin(), refuel.end());
        int idx = 0;
        priority_queue<int> pq;
        int count = 0;

        while(s < target)
        {
            while(idx < n)
            {
                if(refuel[idx].first > s)
                {
                    break;
                }
                pq.push(refuel[idx].second);
                idx++;
            }

            if(pq.empty())
            {
                return -1;
            }

            int curr = pq.top();
            pq.pop();
            s += curr;
            count ++;
        }
        return count;
    }
};