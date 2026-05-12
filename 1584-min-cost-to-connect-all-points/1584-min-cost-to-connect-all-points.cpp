class Solution {
public:

    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<bool> vis(n, false);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        // {cost, node}
        pq.push({0,0});

        int totalCost = 0;

        int edgesUsed = 0;

        while(edgesUsed < n) {

            auto [cost,node] = pq.top();
            pq.pop();

            if(vis[node])
                continue;

            vis[node] = true;

            totalCost += cost;

            edgesUsed++;

            // Add edges to all unvisited nodes
            for(int nei = 0; nei < n; nei++) {

                if(!vis[nei]) {

                    int dist =
                        abs(points[node][0] - points[nei][0]) +
                        abs(points[node][1] - points[nei][1]);

                    pq.push({dist, nei});
                }
            }
        }

        return totalCost;
    }
};