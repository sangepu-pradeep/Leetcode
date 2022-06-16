class Solution {
public:
   
    string longestPalindrome(string s) {
        int st=0; int e=0; int mx=0; int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i>=j) {dp[i][j]=1;continue;}
                if(s[i]==s[j]&&dp[i+1][j-1]) dp[i][j]=1;
                else dp[i][j]=0;
            }
        }
        
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(mx<j-i&&dp[i][j]){
                    mx=j-i;st=i;e=j;
                }
            }
        }
        return s.substr(st,e-st+1);
        
    }
};