class Solution {
public:

    struct cmp
    {
        bool operator() (const pair<int, int> &a, const pair<int, int> &b)
        {
            return a.first < b.first;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,int>, vector<pair<int, int>>, cmp> pq;
        for(int i=0;i<points.size();i++)
        {
            int sq = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            pq.push({sq, i});

            if(pq.size() > k)
            {
                pq.pop();
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