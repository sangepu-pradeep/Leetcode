class Solution {
public:
    bool dfs(vector<vector<int>>&g,vector<int>vis,int node, int s, int d){
        vis[node]=1;
        if(node==d)return 1; bool b=0;
        for(auto a:g[node]){
            if(vis[a]==1) return 0;
            if(dfs(g,vis,a,s,d)==0) return 0;
            b=1;
        }
        if(b==0) return 0;
        return 1;
    }
    bool leadsToDestination(int n, vector<vector<int>>& e, int s, int d) {
        vector<vector<int>>g(n);
        for(auto a:e){
            g[a[0]].push_back(a[1]);
            
        }
        if(g[d].size()>0) return 0;
        vector<int>vis(n,0);
        return dfs(g,vis,s,s,d);
    }
};