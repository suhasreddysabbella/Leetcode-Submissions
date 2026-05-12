class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        // blocked start/end
        if(grid[0][0] == 1 ||
           grid[n-1][n-1] == 1)
            return -1;

        vector<pair<int,int>> dir = {
            {-1,-1},{-1,0},{-1,1},
            {0,-1},        {0,1},
            {1,-1},{1,0},{1,1}
        };

        queue<pair<int,int>> q;

        q.push({0,0});

        grid[0][0] = 1; // visited mark

        int steps = 1;

        while(!q.empty()) {

            int size = q.size();

            for(int i = 0; i < size; i++) {

                auto [r,c] = q.front();
                q.pop();

                // reached destination
                if(r == n-1 && c == n-1)
                    return steps;

                for(auto [dr,dc] : dir) {

                    int nr = r + dr;
                    int nc = c + dc;

                    if(nr >= 0 && nc >= 0 &&
                       nr < n && nc < n &&
                       grid[nr][nc] == 0) {

                        q.push({nr,nc});

                        grid[nr][nc] = 1; // mark visited
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};