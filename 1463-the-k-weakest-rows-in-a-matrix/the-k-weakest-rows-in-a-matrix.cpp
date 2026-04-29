class Solution {
public:

    struct cmp
    {
        bool operator() (const pair<int,int> &a, const pair<int,int> &b)
        {
            if(a.first != b.first)
            {
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    };

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res(mat.size(), 0);

        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j] == 1)
                {   res[i] ++; }
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

        for(int i=0;i<res.size();i++)
        {
            pq.push({res[i], i});
            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};