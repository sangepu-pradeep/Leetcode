class Solution {
public:
    int dp[10001];
    int fun(int t, vector<int>&nums){
        if(dp[t]!=-1) return dp[t];
       if(t==0) return 1; int ans=0;
        for(int i=0;i<nums.size();i++){
            if(t>=nums[i]) ans+=fun(t-nums[i],nums);
        }
        return dp[t]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
     memset(dp,-1,sizeof(dp));
        return fun(target,nums);
    }
};