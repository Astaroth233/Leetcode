class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        vector<pair<int, int>> projects;

        for(int i=0;i<profits.size();i++)
        {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());

        int idx = 0;
        
        while(k --)
        {
            while(idx < projects.size() && projects[idx].first <= w)
            {
                pq.push(projects[idx].second);
                idx++;
            }
            if(pq.empty())
            {
                return w;
            }
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};