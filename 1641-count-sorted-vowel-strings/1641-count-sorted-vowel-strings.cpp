class Solution {
public:

    int fun(int i,int n,vector<vector<int>>&dp){
        if(dp[i][n]!=-1) return dp[i][n];
        if(n==0){
            return 1;
        }
        if(i==5)return 0;
        int ans=0;
      //  ans+=fun(i+1,n-1);
        ans+=fun(i+1,n,dp);
        ans+=fun(i,n-1,dp);
        return dp[i][n]=ans;
    }
    int countVowelStrings(int n) {
        vector<vector<int>>dp(6,vector<int>(n+1,-1));
        return fun(0,n,dp);
    }
};