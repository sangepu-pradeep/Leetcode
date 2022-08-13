class Solution {
public:
    int mod=1e9+7;
    
    int numFactoredBinaryTrees(vector<int>& nums) {
     sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<long>dp(n); int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            long t=1;
            for(int j=0;j<i;j++){
                int r=nums[i];
                if(r%nums[j]==0){
                     int p=r/nums[j];
                    if(mp.count(p)){
                        t+=dp[j]*dp[mp[p]];
                        t=t%mod;
                    }
                    r/=nums[j];
                }
            }
            dp[i]=t;
        
            ans+=t;ans=ans%mod;
        }
        
        return ans;
    }
};