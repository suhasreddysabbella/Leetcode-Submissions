class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int islands=0;
        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j]='0';
                    while(!q.empty()){
                        auto[r,c]=q.front();
                        q.pop();
                        for(auto[dr,dc]:dir){
                            int nr=dr+r;
                            int nc=dc+c;
                            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]=='1'){
                                q.push({nr,nc});
                                grid[nr][nc]='0';
                            }
                        }
                    }
                }

            }
        }
    return islands;
    }
};
