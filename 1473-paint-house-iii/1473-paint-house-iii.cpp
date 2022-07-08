class Solution {
public:
    int dp[101][22][101];
    int fun(int i, int prev,int target, vector<vector<int>>&cost, vector<int>&houses, int n, int m){
        if(target<0) return  -1;
        if(dp[i][prev][target]!=-2) return dp[i][prev][target];
     if(target==0&&i==m){
         return  dp[i][prev][target]=0;
     }   
        if(i==m) return  dp[i][prev][target]=-1;
        int ans=INT_MAX;
        if(houses[i]!=0) {
            int p=target;
            if(prev!=houses[i])p--;
            return  dp[i][prev][target]=fun(i+1,houses[i],p,cost,houses,n,m);
        }
        for(int k=1;k<=n;k++){
           int p=-1;
            if(prev!=k){
                p=fun(i+1,k,target-1,cost,houses,n,m);
            }else p=fun(i+1,k,target,cost,houses,n,m);
            if(p!=-1)
            ans=min(ans,cost[i][k-1]+p);
        }
        if(ans==INT_MAX) return  dp[i][prev][target]=-1;
        return  dp[i][prev][target]=ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        for(int i=0;i<=100;i++){
            for(int j=0;j<=21;j++){
                for(int k=0;k<=100;k++){
                    dp[i][j][k]=-2;
                }
            }
        }
    return fun(0,21,target,cost,houses,n,m);
    }
};