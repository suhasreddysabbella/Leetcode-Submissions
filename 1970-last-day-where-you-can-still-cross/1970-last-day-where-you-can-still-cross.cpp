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

        if(size[pa] < size[pb])
            swap(pa,pb);

        parent[pb] = pa;

        size[pa] += size[pb];
    }
};

class Solution {
public:

    int latestDayToCross(
        int row,
        int col,
        vector<vector<int>>& cells) {

        int total = row * col;

        int top = total;
        int bottom = total + 1;

        DSU dsu(total + 2);

        vector<vector<int>> grid(
            row,
            vector<int>(col, 0)
        );

        vector<pair<int,int>> dir = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        auto id = [&](int r, int c) {
            return r * col + c;
        };

        // Process reverse days
        for(int day = cells.size()-1;
            day >= 0;
            day--) {

            int r = cells[day][0] - 1;
            int c = cells[day][1] - 1;

            grid[r][c] = 1;

            int curr = id(r,c);

            // Connect top row
            if(r == 0) {
                dsu.unite(curr, top);
            }

            // Connect bottom row
            if(r == row-1) {
                dsu.unite(curr, bottom);
            }

            // Connect neighboring lands
            for(auto [dr,dc] : dir) {

                int nr = r + dr;
                int nc = c + dc;

                if(nr >= 0 &&
                   nc >= 0 &&
                   nr < row &&
                   nc < col &&
                   grid[nr][nc] == 1) {

                    dsu.unite(curr,
                              id(nr,nc));
                }
            }

            // Path exists
            if(dsu.find(top) ==
               dsu.find(bottom)) {

                return day;
            }
        }

        return -1;
    }
};