class Solution {
public:
    int fun(int num,vector<int>&dp){
    if(dp[num]!=-1) return dp[num];
        if(num==0) return 0;
        int ans=INT_MAX;
        if(num%2==0)ans=1+fun(num/2,dp);
        ans=min(ans,1+fun(num-1,dp));
        return dp[num]=ans;
    }
    int numberOfSteps(int num) {
        vector<int>dp(num+1,-1);
        return fun(num,dp);
    }
};