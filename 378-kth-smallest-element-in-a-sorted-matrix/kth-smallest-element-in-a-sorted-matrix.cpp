class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        class Node
        {
            public:
            int val;
            int row;
            int col;

            Node(int v, int r, int c)
            {
                val = v;
                row = r;
                col = c;
            }
        };

        struct cmp
        {
            bool operator()(const Node &a, const Node &b)
            {
                return a.val > b.val;
            }
        };

        int n = matrix.size();
        int m = matrix[0].size();
        priority_queue<Node, vector<Node>, cmp> pq;

        for(int i=0;i<n;i++)
        {
            pq.push({matrix[i][0], i, 0});
        }

         int count = 0;

        while(!pq.empty()) 
        {
            Node curr = pq.top();
            pq.pop();

            count++;
            if(count == k) return curr.val;

            int row = curr.row;
            int col = curr.col;

            if(col + 1 < m) 
            {
                pq.push(Node(matrix[row][col + 1], row, col + 1));
            }
        }
        return -1;
    }
};