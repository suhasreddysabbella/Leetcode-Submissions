class Solution {
public:

    vector<int> parent;

    int find(int x) {

        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {

        int pu = find(u);
        int pv = find(v);

        if(pu == pv)
            return false;

        parent[pu] = pv;

        return true;
    }

    vector<int> findRedundantDirectedConnection(
        vector<vector<int>>& edges) {

        int n = edges.size();

        vector<int> indegree(n + 1, -1);

        vector<int> cand1, cand2;

        // Detect node with two parents
        for(int i = 0; i < n; i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            if(indegree[v] == -1) {

                indegree[v] = i;
            }
            else {

                cand1 = edges[indegree[v]];
                cand2 = edges[i];

                // Invalidate second edge temporarily
                edges[i][1] = -1;
            }
        }

        parent.resize(n + 1);

        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // Union Find cycle detection
        for(auto &e : edges) {

            int u = e[0];
            int v = e[1];

            if(v == -1)
                continue;

            if(!unite(u,v)) {

                // Case 1: only cycle
                if(cand1.empty())
                    return e;

                // Case 3
                return cand1;
            }
        }

        // Case 2
        return cand2;
    }
};