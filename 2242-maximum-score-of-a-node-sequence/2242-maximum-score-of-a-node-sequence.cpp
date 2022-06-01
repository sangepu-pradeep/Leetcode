class Solution {
public:
   int fun(vector<int>&vis,int node,vector<vector<int>>&g, vector<int>&s, int d){
      
       if(d==1) return s[node];
        vis[node]=1;int ans=-1;
       int rr=g[node].size();
       int t=min(4,rr);
       for(int i=0;i<t;i++){
           int a=g[node][i];
           if(vis[a]==0){
                 int p=fun(vis,a,g,s,d-1);
               if(p!=-1) ans=max(ans,s[node]+p);
           }
       }
       vis[node]=0;
       return ans;
       
   }
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
       vector<vector<int>>g(scores.size()); int n=scores.size();
        for(auto a:edges){
            g[a[0]].push_back(a[1]);
            g[a[1]].push_back(a[0]);
        }
        auto comp=[&scores](const auto &a,const auto &b){
           return scores[a]>scores[b]; 
        };
        for(int i=0;i<n;i++){
            sort(g[i].begin(),g[i].end(),comp);
            int p=g[i].size();
            int t=min(p,3);
            g[i].resize(t);
        }
      int ans=-1;
        for(auto e:edges){
            for(auto s:g[e[0]]){
                for(auto en:g[e[1]]){
                    if(e[0]==en||e[1]==s||s==en) continue;
                    ans=max(ans,scores[s]+scores[en]+scores[e[1]]+scores[e[0]]);
                }
            }
        }
       
        return ans;
    }
};