class Solution {
public:
    long dp[201][201];
    long long fun(int r, int c, map<pair<int,int>,int>&mp){
        if(dp[r][c]!=-1) return dp[r][c];
        if(r==1&&c==1) return mp[{1,1}];
        long ans=mp[{r,c}];
        for(int i=1;i<r;i++){
           long t=fun(r-i,c,mp)+fun(i,c,mp);
            if(t>ans) ans=t;
        }
        for(int j=1;j<c;j++){
            long t=fun(r,c-j,mp)+fun(r,j,mp);
            if(t>ans) ans=t;
        }
        return dp[r][c]=ans;
    }
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        map<pair<int,int>,int>mp;
        for(auto a:prices){
            mp[{a[0],a[1]}]=a[2];
        }
        memset(dp,-1,sizeof(dp));
        return fun(m,n,mp);
    }
};