class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++)
        {
            pq.push(stones[i]);
        }

        while(pq.size() > 1)
        {
            int pf = pq.top();
            pq.pop();
            int ps = pq.top();
            pq.pop();

            if(pf !=ps)
            {
                int diff = pf - ps;
                pq.push(diff);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};