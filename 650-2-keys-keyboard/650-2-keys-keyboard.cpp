class Solution {
public:
    int dp[1001][1001];
    int fun(int i, int n, int total){
             if(n<0)return 1e9;
        if(n==0) return dp[i][n]=0;
    
        int ans=1+fun(i,n-i,total);
         ans=min(ans,2+fun(total-n,n-(total-n),total));
                return dp[i][n]=ans;
    }
    int minSteps(int n) {
       memset(dp,-1,sizeof(dp));
        if(n==1) return 0;
        return 1+fun(1,n-1,n);
    }
};