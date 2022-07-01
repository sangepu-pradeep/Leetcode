class Solution {
public:
    int dp[101][4];
    int fun(int i, int prev, vector<vector<int>>&c){
        if(i==c.size()) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        int ans=INT_MAX;
         for(int k=0;k<3;k++){
             if(k==prev) continue;
             ans=min(ans,c[i][k]+fun(i+1,k,c));
         }
        return dp[i][prev]=ans;
    }
    int minCost(vector<vector<int>>& costs) {
        memset(dp,-1,sizeof(dp));
        return fun(0,3,costs);
    }
};