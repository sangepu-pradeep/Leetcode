class Solution {
public:
    int mod=1337;
    int fun(int a, int b){
        if(b==0) return 1;
        if(b%2==0){
            long t=fun(a,b/2);
            return (t*t)%mod;
        }
   
            long t=fun(a,b/2);
            t=t*t;t=t%mod;
            t*=a;
            return t;
       
    }
    int superPow(int a, vector<int>& b) {
        int n=b.size();
        vector<long>dp(n);
        dp[n-1]=a%mod;
        for(int i=n-2;i>=0;i--){
            dp[i]=fun(dp[i+1],10);
            dp[i]=dp[i]%mod;
        }
        long ans=1;
        for(int i=n-1;i>=0;i--){
            ans=ans*fun(dp[i],b[i]);
            ans=ans%mod;
        }
        return (int)ans;
    }
};