class Solution {
public:
    int dirx[4]={0,0,-1,1};
    int diry[4]={1,-1,0,0};
   
    void dfs(vector<vector<int>>&vis,int x,int y, vector<vector<int>>&h){
        vis[x][y]=1;   int r=h.size(); int c=h[0].size();
        for(int i=0;i<4;i++){
            int x1=x+dirx[i];
            int y1=y+diry[i];
            if(x1>=0&&x1<r&&y1>=0&&y1<c&&vis[x1][y1]==0&&h[x1][y1]>=h[x][y]){
                dfs(vis,x1,y1,h);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
    
        int r=h.size(); int c=h[0].size();
        vector<vector<int>>visp(r,vector<int>(c,0));
        vector<vector<int>>visa(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            dfs(visp,i,0,h);
            dfs(visa,i,c-1,h);
        }
        for(int j=0;j<c;j++){
            dfs(visp,0,j,h);
            dfs(visa,r-1,j,h);
        }
        vector<vector<int>>ans;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(visp[i][j]&&visa[i][j]){
                  ans.push_back({i,j});  
                }
            }
        }
        return ans;
        
    }
};