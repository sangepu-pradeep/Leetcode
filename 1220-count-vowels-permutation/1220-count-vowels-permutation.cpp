class Solution {
public:
    int countVowelPermutation(int n) {
        int mod=1e9+7;
        vector<long>dp(5,1); int ans=0;
        for(int i=n-1;i>0;i--){
            long t=0;
        vector<long>mp(5);
            mp[4]+=dp[0];
            mp[3]=dp[2]+dp[4];
            mp[2]=dp[0]+dp[1]+dp[3]+dp[4];
            mp[1]=dp[0]+dp[2];
            mp[0]=dp[1];
            for(int i=0;i<5;i++)mp[i]=mp[i]%mod;
            dp=mp;
        }
        for(int i=0;i<5;i++){
            ans+=dp[i]; ans=ans%mod;
        }
        return ans;
    }
};