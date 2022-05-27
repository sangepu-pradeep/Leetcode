class Solution {
public:
   int dp[100001];
    int fun(int mask, vector<vector<int>>&g, int n, int k){
        if(mask==((1<<n)-1)) return 0;
        if(dp[mask]!=-1)return dp[mask];
        vector<int>in(n);
        for(int i=0;i<n;i++){
            if(mask&(1<<i))continue;
            for(auto a:g[i]){
                in[a]++;
            }
        }
        int temp=0;
        for(int i=0;i<n;i++){
            if(in[i]==0&&(mask&(1<<i))==0){
                temp|=(1<<i);
            }
        }
        int p=temp; int ans=INT_MAX;
        int cnt=__builtin_popcount(p);
        if(cnt>k){
            for(int s=temp;s>0;s=((s-1)&temp)){
                int b=__builtin_popcount(s);
                if(b==k){
                    ans=min(ans,1+fun(mask|s,g,n,k));
                }
            }
        }
        else {
            ans=1+fun(mask|temp,g,n,k);
        }
        return dp[mask]=ans;
    }
    int minNumberOfSemesters(int n, vector<vector<int>>& r, int k) {
        vector<vector<int>>g(n);
        for(auto a:r){
            a[0]--; a[1]--;
            g[a[0]].push_back(a[1]);
        }
   memset(dp,-1,sizeof(dp));
   
 
       return  fun(0,g,n,k);
    }
};