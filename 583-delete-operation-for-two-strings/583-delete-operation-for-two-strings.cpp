class Solution {
public:
    int dp[501][501];
    int fun(int i, int j, string &s1, string &s2){
        if(i==s1.size()) return s2.size()-j;
        if(j==s2.size()) return s1.size()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return fun(i+1,j+1,s1,s2);
        return dp[i][j]=min(1+fun(i+1,j,s1,s2),1+fun(i,j+1,s1,s2));
    }
    int minDistance(string word1, string word2) {
      memset(dp,-1,sizeof(dp));
        return fun(0,0,word1,word2);
    }
};