class Solution {
public:
    int dirx[4]={1,-1,0,0};
    int diry[4]={0,0,-1,1};
    bool valid(int x, int y, int r, int c){
        return x>=0&&x<r&&y>=0&&y<c;
    }
    int mod=1e9+7;
     int dp[51][51][51];
    int fun(int x, int y, int m, int r, int c){
        if(dp[x][y][m]!=-1) return dp[x][y][m];
       if(m==0){
           int l=0;
          return 0;
       }
   int ans=0;
        for(int i=0;i<4;i++){
           int x1=x+dirx[i]; int y1=y+diry[i];
            if(valid(x1,y1,r,c)) ans+=fun(x1,y1,m-1,r,c);
            else ans++;
            ans=ans%mod;
        }
        return dp[x][y][m]=ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        if(maxMove==0) return 0;
        return fun(startRow,startColumn,maxMove,m,n);
    }
};