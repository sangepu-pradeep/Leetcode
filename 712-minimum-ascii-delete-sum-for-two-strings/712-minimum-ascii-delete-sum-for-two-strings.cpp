class Solution {
public:
    
    int fun(string &s1, string &s2, int i, int j,vector<vector<int>>&dp){
      
        if(i==s1.size()||j==s2.size()){
            int temp=0;
            while(j<s2.size()){
                temp+=((int)s2[j]);j++;
            }
            while(i<s1.size()){
                temp+=((int)s1[i]);i++;
            }
            return dp[i][j]=temp;
        }  if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j]) return dp[i][j]=fun(s1,s2,i+1,j+1,dp);
        ans=(int)s1[i]+fun(s1,s2,i+1,j,dp);
        ans=min(ans,(int)s2[j]+fun(s1,s2,i,j+1,dp));
        return dp[i][j]=ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        int t1=s1.size(); int t2=s2.size();
        vector<vector<int>>dp(t1+1,vector<int>(t2+1,-1));
        return fun(s1,s2,0,0,dp);
    }
};