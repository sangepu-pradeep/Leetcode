class Solution {
public:
    bool fun(int node,int &n,vector<int>&vis,vector<vector<int>>&g, int s, int e){
        vis[node]=1;n--;
        if(n==0) return 1;
        for(auto a:g[node]){
            if(node==s&&a==e)continue;
           
            if(vis[a]==0&&fun(a,n,vis,g,s,e)) return 1;
        }
        
        return 0;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& e) {
        int n=e.size();
        vector<int>in(n+1); vector<vector<int>>g(n+1);
       for(auto a:e){
           in[a[1]]++; g[a[0]].push_back(a[1]);
       }
        vector<int>vis(n+1);
        reverse(e.begin(),e.end());
        for(auto a:e){
            in[a[1]]--;;
            for(int i=1;i<=n;i++){
                int p=n; 
                if(in[i]==0) {
                  int b=fun(i,p,vis,g,a[0],a[1]);
               
                    if(b==1) return a;
                   for(int i=1;i<=n;i++)vis[i]=0;
                    break;
                }
               
            }
            in[a[1]]++;
        }
        return {};
    }
};