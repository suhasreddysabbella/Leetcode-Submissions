class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times,
                         int n,
                         int k) {

        vector<vector<pair<int,int>>> adj(n + 1);

        // Build graph
        for(auto &t : times) {

            int u = t[0];
            int v = t[1];
            int w = t[2];

            adj[u].push_back({v,w});
        }

        vector<int> dist(n + 1, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[k] = 0;

        pq.push({0,k});

        while(!pq.empty()) {

            auto [d,node] = pq.top();
            pq.pop();

            // Skip outdated entry
            if(d > dist[node])
                continue;

            for(auto [neigh,wt] : adj[node]) {

                if(dist[node] + wt < dist[neigh]) {

                    dist[neigh] = dist[node] + wt;

                    pq.push({dist[neigh], neigh});
                }
            }
        }

        int ans = 0;

        // Find maximum shortest distance
        for(int i = 1; i <= n; i++) {

            if(dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};