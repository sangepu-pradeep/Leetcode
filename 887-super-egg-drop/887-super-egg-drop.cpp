class Solution {
public:
      int fun(int n, int k,vector<vector<int>>&dp){
          if(n<0) return 0;
          if(dp[n][k]!=-1) return dp[n][k];
          if(k==1) return n;// n-(i+1)+1, i+1 
          if(n==1) return 1;
          if(n<=0) return 0;
        //  int ans=INT_MAX;
//           for(int i=0;i<n;i++){
//               ans=min(ans,1+max(fun(i,k-1,dp),fun(n-(i+1),k,dp)));
              
//           }
          int l=1; int h=n; int ans=INT_MAX;
          while(l<=h){
              int mid=(l+h)/2;
              int t=fun(mid-1,k-1,dp); int p=fun(n-(mid),k,dp);
            //  int p=1+max(fun(mid-1,k-1,dp),fun(n-(mid),k,dp));
              // if(mid==l) {l=mid+1;ans=min(p,ans);continue;}
              // int t=1+max(fun(mid-2,k-1,dp),fun(n-(mid-1),k,dp));
              // if(p-t<0) {l=mid+1;ans=min(ans,p);}
              // else {h=mid-1;ans=min(ans,t);}
              if(t>p) h=mid-1;
              else l=mid+1;
              ans=min(ans,1+max(p,t));
          }
          return dp[n][k]=ans;
      }
       
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return fun(n,k,dp);
    }
};