class Solution {
public:
    int dp[1001];
    bool valid(int a, int b, vector<string>&words){
        int i=0; int j=0;
        if(words[a].size()+1!=words[b].size()) return 0;
        bool bb=0;
        while(i<words[a].size()){
            if(words[a][i]!=words[b][j]){
               if(bb==0) {j++;bb=1;}
                else return 0;
            }else {i++;j++;}
        }
        return 1;
    }
   int fun(int i,vector<string>&words){
       if(i==words.size()) return 0;
       if(dp[i]!=-1) return dp[i];
       int ans=1;
      for(int k=i+1;k<words.size();k++){
          if(valid(i,k,words)){
             ans=max(1+fun(k,words),ans); 
          }
      } 
       return dp[i]=ans;
   }
    int longestStrChain(vector<string>& words) {  
        auto comp=[](const auto &a, const auto &b){
            return a.size()<b.size();
        };
      sort(words.begin(),words.end(),comp);
       int ans=0; memset(dp,-1,sizeof(dp));
        for(int i=0;i<words.size();i++){
            ans=max(ans,fun(i,words));
        }
       return ans; 
    }
};