class Solution {
public:

    struct cmp
    {
        bool operator() (const pair<int, string> &a, const pair<int, string> &b)
        {
            if(a.first != b.first)
            {
                return a.first > b.first;
            }
            return a.second < b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> f;

        for(int i=0;i<words.size();i++)
        {
            f[words[i]] ++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

        for(auto i : f)
        {
            pq.push({i.second, i.first});

            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<string> res;

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};