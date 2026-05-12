class Solution {
public:

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> color(n, -1);

        queue<int> q;

        for(int i = 0; i < n; i++) {

            if(color[i] != -1)
                continue;

            color[i] = 0;
            q.push(i);

            while(!q.empty()) {

                int node = q.front();
                q.pop();

                for(int neigh : graph[node]) {

                    // not colored yet
                    if(color[neigh] == -1) {

                        color[neigh] = 1 - color[node];
                        q.push(neigh);
                    }

                    // conflict
                    else if(color[neigh] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};