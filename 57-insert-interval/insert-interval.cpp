class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int si = newInterval[0];
        int ei = newInterval[1];
        bool pushed = false;

        for(int i=0;i<intervals.size();i++)
        {
            int s = intervals[i][0];
            int e = intervals[i][1];
            if(!pushed && (s >= si))
            {
                res.push_back({si, ei});
                pushed = true;
            }
            res.push_back({s,e});
        }
        if(!pushed)
        {
            res.push_back({si, ei});
        }
        return merge(res);
    }

    vector<vector<int>> merge(vector<vector<int>>& res)
    {
        int s1 = res[0][0];
        int e1 = res[0][1];
        vector<vector<int>> result;

        for(int i=1;i<res.size();i++)
        {
            int s2 = res[i][0];
            int e2 = res[i][1];

            if(e1 >= s2)
            {
                e1 = max(e1, e2);
                continue;
            }
            result.push_back({s1, e1});
            s1 = s2;
            e1 = e2;
        }
        result.push_back({s1, e1});
        return result;
    }

};