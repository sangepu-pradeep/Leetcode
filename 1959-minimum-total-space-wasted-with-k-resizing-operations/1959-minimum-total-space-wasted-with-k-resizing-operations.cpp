class Solution {
public:
    int dp[201][201];
    int fun(int i, int k, vector<int>&nums){
            if(i==nums.size()) return 0;
         if(k<0){
           return 1e9;
       }
       
           if(dp[i][k]!=-1) return dp[i][k];
     
     
      
        int mx=nums[i]; int ans=INT_MAX;
        int sum=0;
        for(int j=i;j<nums.size();j++){
            mx=max(mx,nums[j]);sum+=nums[j];
           ans=min(ans,(j-i+1)*mx-sum+fun(j+1,k-1,nums));
         
        }
        return dp[i][k]=ans;
        
    }
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return fun(0,k,nums);
    }
};