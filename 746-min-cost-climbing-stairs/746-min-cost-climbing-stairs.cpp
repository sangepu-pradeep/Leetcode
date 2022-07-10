class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
       vector<int>dp(n+1,0);//dp[i] is the min cost to reach index i;
        for(int i=2;i<=n;i++){
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};