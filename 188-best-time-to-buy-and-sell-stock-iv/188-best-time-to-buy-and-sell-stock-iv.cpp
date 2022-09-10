class Solution {
public:
    int dp[101][1001][2];
    int fun(int k, int i, int b,vector<int>&nums){
        if(dp[k][i][b]!=-1) return dp[k][i][b];
        if(i==nums.size()) return 0;
        int ans=0;
        if(b==1){
            if(k)  ans=max(ans,-nums[i]+fun(k-1,i+1,0,nums));
            ans=max(ans,fun(k,i+1,b,nums));
        }
      else{
          ans=max(ans,nums[i]+fun(k,i+1,1,nums));
          ans=max(ans,fun(k,i+1,b,nums));
      }
      return dp[k][i][b]=ans;  
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return fun(k,0,1,prices);
    }
};