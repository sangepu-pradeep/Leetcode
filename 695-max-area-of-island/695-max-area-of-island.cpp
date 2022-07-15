class Solution {
public:
    int dirx[4]={1,-1,0,0};
    int diry[4]={0,0,-1,1};
    bool valid(int x, int y, vector<vector<int>>&grid){
        int r=grid.size(); int c=grid[0].size();
        return x>=0&&x<r&&y>=0&&y<c;
    }
    int dfs(int x, int y, vector<vector<int>>&grid,vector<vector<int>>&vis){
       vis[x][y]=1; int ans=1;
        for(int i=0;i<4;i++){
            int x1=x+dirx[i];
            int y1=y+diry[i];
            if(valid(x1,y1,grid)&&vis[x1][y1]==0&&grid[x1][y1]==1) ans+=dfs(x1,y1,grid,vis);
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int ans=0;
        int r=grid.size(); int c=grid[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
       
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               if(grid[i][j]==1&&vis[i][j]==0) ans=max(ans,dfs(i,j,grid,vis));
            }
        }
        return ans;
    }
};