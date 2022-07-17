class Solution {
public:
    int mod=1e9+7;
    int dp[1001][1001];
    int fun(int n,int k){
        if(k<0) return 0;
        if(dp[n][k]!=-1) return dp[n][k];
        if(n==1&&k==0) return 1;
        else if(n==1) return 0;
        if(k==0) return 1;
     if(n==1) return 1;
         
   
   
        int ans=0;
//      for(int i=0;i<n;i++){
    
//          if(k-i<0)break;
//          ans+=fun(n-1,k-i);
//          //if(n==3) cout<<fun(n-1,k-i)<<endl;
//          ans=ans%mod;
//      }n,k-1
        ans+=fun(n-1,k); ans=ans%mod;
        ans+=fun(n,k-1);ans=ans%mod;
        if(k>=n){
            ans=(ans+mod-fun(n-1,k-n))%mod;
        }
      return dp[n][k]=ans; 
    }
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return fun(n,k);
    }
};