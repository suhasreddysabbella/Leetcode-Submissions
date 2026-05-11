class Solution {
public:
    int n,m;
    int dfs(int r,int c,int n,int m,vector<vector<int>>& grid){
        if(r<0 || c<0 || r>=n ||c>=m){
            return 0;
        }
        if(grid[r][c]==0){
            return 0;
        }
        grid[r][c]=0;
        int area=1;
        area+=dfs(r+1,c,n,m,grid);
        area+=dfs(r-1,c,n,m,grid);
        area+=dfs(r,c+1,n,m,grid);
        area+=dfs(r,c-1,n,m,grid);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int maxarea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area=dfs(i,j,n,m,grid);
                    maxarea=max(maxarea,area);
                }
            }
        }
        return maxarea;
    }
};