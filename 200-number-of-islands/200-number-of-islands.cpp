class Solution {
public:
    int dirx[4]={1,-1,0,0};
    int diry[4]={0,0,-1,1};
    void dfs(int x, int y, vector<vector<char>>&grid,vector<vector<int>>&vis){
        vis[x][y]=1;
        int r=grid.size(); int c=grid[0].size();
        for(int i=0;i<4;i++){
            int x1=x+dirx[i];
            int y1=y+diry[i];
            if(y1>=0&&y1<c&&x1>=0&&x1<r&&vis[x1][y1]==0&&grid[x1][y1]=='1')dfs(x1,y1,grid,vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
       int r=grid.size(); int c=grid[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0)); int cnt=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(vis[i][j]==0&&grid[i][j]=='1'){dfs(i,j,grid,vis);cnt++;}
            }
        }
        return cnt;
    }
};