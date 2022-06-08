class Solution {
public:
    int dp[1<<16];
    int countTriplets(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        int t=(1<<16);
      for(int i=0;i<t;i++){
          for(auto a:nums){
              if((a&i)==0)dp[i]++;
          }
      }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                 int t=nums[i]&nums[j];
                 ans+=dp[t];
            }
        }
        return ans;
        
    }
};