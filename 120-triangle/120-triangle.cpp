class Solution {
public:
    int dp[210][210];
    int fun(int x,int y,vector<vector<int>>&t){
        if(dp[x][y]!=-1) return dp[x][y];
        if(x==t.size()) return 0;
        int ans=t[x][y]+fun(x+1,y,t);
        ans=min(ans,t[x][y]+fun(x+1,y+1,t));
        return dp[x][y]=ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,triangle);
    }
};