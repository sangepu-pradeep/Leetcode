class Solution {
public:
    int dirx[4]={1,-1,0,0};
    int diry[4]={0,0,-1,1};
    void dfs(vector<vector<int>>&b, int x, int y, int col, int org){
        b[x][y]=col;
         int r=b.size(); int c=b[0].size();
        for(int i=0;i<4;i++){
            int x1=x+dirx[i];
            int y1=y+diry[i];
            if(x1>=0&&y1>=0&&x1<r&&y1<c&&b[x1][y1]==org){
                dfs(b,x1,y1,col,org);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> im, int sr, int sc, int col) {
        if(im[sr][sc]==col) return im;
       dfs(im,sr,sc,col,im[sr][sc]);
        return im;
    }
};