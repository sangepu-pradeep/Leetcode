class Solution {
public:
    int dp[101][101][201];
    int fun(int i,int j, int k, string &s1, string &s2, string &s3){
        if(k==s3.size()) return 1;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int ans=0;
        if(s1[i]==s3[k])ans=ans|(fun(i+1,j,k+1,s1,s2,s3));
        if(s2[j]==s3[k])ans=ans|(fun(i,j+1,k+1,s1,s2,s3));
        return dp[i][j][k]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
       memset(dp,-1,sizeof(dp));
        if(s3.size()!=s1.size()+s2.size()) return 0;
        return fun(0,0,0,s1,s2,s3);
    }
};