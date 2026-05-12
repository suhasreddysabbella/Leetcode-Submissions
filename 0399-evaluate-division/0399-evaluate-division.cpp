class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> adj;
        double dfs(string src,
               string dst,
               unordered_set<string>& vis,
               double product) {

        // Destination reached
        if(src == dst)
            return product;

        vis.insert(src);

        for(auto [neigh, wt] : adj[src]) {

            if(!vis.count(neigh)) {

                double ans =
                    dfs(neigh,
                        dst,
                        vis,
                        product * wt);

                if(ans != -1.0)
                    return ans;
            }
        }

        return -1.0;}
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0; i < equations.size(); i++) {

            string a = equations[i][0];
            string b = equations[i][1];

            double val = values[i];

            adj[a].push_back({b, val});

            adj[b].push_back({a, 1.0 / val});
        }

        vector<double> result;

        for(auto &q : queries) {

            string src = q[0];
            string dst = q[1];

            // Variable doesn't exist
            if(adj.find(src) == adj.end() ||
               adj.find(dst) == adj.end()) {

                result.push_back(-1.0);
                continue;
            }

            unordered_set<string> vis;

            result.push_back(
                dfs(src, dst, vis, 1.0)
            );
        }

        return result;
    }
};