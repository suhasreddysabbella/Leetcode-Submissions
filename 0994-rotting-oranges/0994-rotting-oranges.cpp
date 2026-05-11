class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }

            }
        }
        if(fresh==0){
            return 0;
        }
        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        int minutes=0;
        while(!q.empty()){
            int size=q.size();
            bool rotting=false;
            for(int i=0;i<size;i++){
                auto[r,c]=q.front();
                q.pop();
                for(auto[dr,dc]:dir){
                    int nr=dr+r;
                    int nc=dc+c;
                    if(nr>=0 && nc>=0 && nr<n && nc <m && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        fresh--;
                        q.push({nr,nc});
                        rotting=true;
                    }
                }
            }
            if(rotting){
                 minutes++;
        }
        }
        
     return (fresh==0) ? minutes : -1;
    }
};