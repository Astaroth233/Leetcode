class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        struct cmp
        {
            bool operator()(const pair<int, int> &a, const pair<int, int> &b)
            {
                if(a.first != b.first)
                {
                    return a.first > b.first;
                }
                return a.second > b.second;
            }
        };

        unordered_map<int, int> m;
        for(int i : nums)
        {
            m[i] ++;
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, cmp > pq;
        for(auto i : m)
        {
            int element = i.first;
            int freq = i.second;
            pair<int, int> curr = {freq, element};
            if(pq.size() < k)
            {
                pq.push(curr);
                continue;
            }
            if(curr.first < pq.top().first)
            {
                continue;
            }
            pq.pop();
            pq.push(curr);
        }

        vector<int> res;
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
        
    }
};