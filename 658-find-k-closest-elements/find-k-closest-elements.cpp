class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        struct cmp
        {
            bool operator()(const pair<int, int> &a, const pair<int, int> &b)
            {
                return a.first < b.first;
            }
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp > pq;
        for(int i=0;i<arr.size();i++)
        {
            int diff = abs(arr[i] - x);
            if(pq.size() < k)
            {
                pq.push({diff, i});
            }
            else if((pq.top().first > diff) || (pq.top().first == diff && arr[pq.top().second] > arr[i]))
            {
                pq.pop();
                pq.push({diff, i});
            }
        }

        vector<int> res;
        while(!pq.empty())
        {
            res.push_back(arr[pq.top().second]);
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};