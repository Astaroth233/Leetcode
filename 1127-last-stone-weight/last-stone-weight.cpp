class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1)
        {
            return stones[0];
        }

        priority_queue<int> pq;
        for(int i : stones)
        {
            pq.push(i);
        }

        while(!pq.empty() && pq.size() > 1)
        {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(x == y)
            {
                continue;
            }
            else
            {
                y = y - x;
                pq.push(y);
            }
        }
        return pq.empty() ? 0 : pq.top();

    }
};