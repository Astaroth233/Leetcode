class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        struct cmp{
            bool operator()(const pair<int, int> &a, const pair<int, int> &b)
            {
                return a.first < b.first;
            }
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp > pq;
        for(int i=0;i<points.size();i++)
        {
            int f = (points[i][0] - 0) * (points[i][0] - 0);
            int s = (points[i][1] - 0) * (points[i][1] - 0);
            int dist = f + s;

            if(pq.size() < k)
            {
                pq.push({dist, i});
                continue;
            }
            if(pq.top().first > dist)
            {
                pq.pop();
                pq.push({dist, i});
            }
        }

        vector<vector<int>> res;
        while(!pq.empty())
        {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};