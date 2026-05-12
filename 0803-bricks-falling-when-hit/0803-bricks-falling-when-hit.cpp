class DSU {
public:

    vector<int> parent, size;

    DSU(int n) {

        parent.resize(n);
        size.resize(n,1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {

        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {

        int pa = find(a);
        int pb = find(b);

        if(pa == pb)
            return;

        parent[pb] = pa;

        size[pa] += size[pb];
    }

    int getSize(int x) {

        return size[find(x)];
    }
};

class Solution {
public:

    vector<int> hitBricks(
        vector<vector<int>>& grid,
        vector<vector<int>>& hits) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> copy = grid;

        // Remove all hit bricks
        for(auto &h : hits) {

            int r = h[0];
            int c = h[1];

            if(copy[r][c] == 1)
                copy[r][c] = 0;
        }

        int roof = n * m;

        DSU dsu(n * m + 1);

        vector<pair<int,int>> dir = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        auto id = [&](int r, int c) {
            return r * m + c;
        };

        // Build DSU
        for(int r = 0; r < n; r++) {

            for(int c = 0; c < m; c++) {

                if(copy[r][c] == 0)
                    continue;

                int curr = id(r,c);

                // Top row connected to roof
                if(r == 0) {
                    dsu.unite(curr, roof);
                }

                for(auto [dr,dc] : dir) {

                    int nr = r + dr;
                    int nc = c + dc;

                    if(nr >= 0 &&
                       nc >= 0 &&
                       nr < n &&
                       nc < m &&
                       copy[nr][nc] == 1) {

                        dsu.unite(curr,
                                  id(nr,nc));
                    }
                }
            }
        }

        vector<int> ans(hits.size());

        // Process hits backwards
        for(int i = hits.size()-1; i >= 0; i--) {

            int r = hits[i][0];
            int c = hits[i][1];

            // No brick originally
            if(grid[r][c] == 0) {
                ans[i] = 0;
                continue;
            }

            int before = dsu.getSize(roof);

            copy[r][c] = 1;

            int curr = id(r,c);

            // Connect to roof if top row
            if(r == 0) {
                dsu.unite(curr, roof);
            }

            // Connect neighbors
            for(auto [dr,dc] : dir) {

                int nr = r + dr;
                int nc = c + dc;

                if(nr >= 0 &&
                   nc >= 0 &&
                   nr < n &&
                   nc < m &&
                   copy[nr][nc] == 1) {

                    dsu.unite(curr,
                              id(nr,nc));
                }
            }

            int after = dsu.getSize(roof);

            ans[i] =
                max(0, after - before - 1);
        }

        return ans;
    }
};