class Solution {
public:

    vector<pair<int,int>> dir = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };

    void dfs(int r, int c,
             vector<vector<int>>& image,
             int origColor,
             int newColor) {

        // change color
        image[r][c] = newColor;

        int n = image.size();
        int m = image[0].size();

        for(auto [dr,dc] : dir) {

            int nr = r + dr;
            int nc = c + dc;

            if(nr >= 0 && nc >= 0 &&
               nr < n && nc < m &&
               image[nr][nc] == origColor) {

                dfs(nr, nc, image,
                    origColor,
                    newColor);
            }
        }
    }

    vector<vector<int>> floodFill(
        vector<vector<int>>& image,
        int sr, int sc, int color) {

        int origColor = image[sr][sc];

        // If already same color, no need
        if(origColor == color)
            return image;

        dfs(sr, sc, image,
            origColor,
            color);

        return image;
    }
};