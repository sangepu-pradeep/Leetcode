class Solution {
public:
    int vis[50001][26];
    int numMatchingSubseq(string s, vector<string>& words) {
       memset(vis,-1,sizeof(vis)); vector<int>curr(26,-1);
        for(int i=s.size()-1;i>=0;i--){
            curr[s[i]-'a']=i;
            for(int j=0;j<26;j++){
                vis[i][j]=curr[j];
            }
           
        }
        int ans=0;
        for(auto a:words){
            int j=0; bool b=0;
           for(int i=0;i<a.size();i++){
              if(vis[j][a[i]-'a']==-1){ b=1;break;}
               else {
                   j=vis[j][a[i]-'a'];
                   if(i+1<a.size()&&a[i+1]==a[i]&&s[j]==a[i])j++;
               }
           }
            if(b==0) ans++;
        }
        return ans;
    }
};