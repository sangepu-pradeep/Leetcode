class Solution {
public:
    // int i is in nums, int j is in mul

    int fun(int i, int j,vector<int>&nums,vector<int>&mul,vector<vector<int>>&dp){
  if(j==mul.size())return 0;
        if(dp[i][j]!=INT_MIN) return dp[i][j];

        int n=nums.size();
       int b=n-1-(j-i);
     
        return dp[i][j]=max(nums[b]*mul[j]+fun(i,j+1,nums,mul,dp),nums[i]*mul[j]+fun(i+1,j+1,nums,mul,dp));
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=multipliers.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MIN));
         return fun(0,0,nums,multipliers,dp);
    }
};