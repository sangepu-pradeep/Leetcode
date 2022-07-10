class Solution {
public:
    int dp[1001];
    int fun(int i,vector<int>&cost){
        if(i>=cost.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MAX;
        ans=cost[i]+fun(i+1,cost);
        ans=min(ans,cost[i]+fun(i+2,cost));
        return dp[i]=ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return min(fun(0,cost),fun(1,cost));
    }
};