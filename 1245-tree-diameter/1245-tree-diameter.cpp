class Solution {
public:
    int ans;
    int fun(int node,vector<vector<int>>&g,vector<int>&vis){
        vis[node]=1;
        priority_queue<int>pq;
        for(auto a:g[node]){
            if(vis[a]==0){
               int t=1+fun(a,g,vis);
                pq.push(t);
            }
        }
        int b=2;  int sum=0;int l=0;
        if(pq.size())l=pq.top();
        while(b--&&pq.size()){
            sum+=pq.top();pq.pop();
        }
        ans=max(ans,sum);
        return l;
    }
    int treeDiameter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>g(n);
        for(auto a:edges){
            g[a[0]].push_back(a[1]);
            g[a[1]].push_back(a[0]);
        }
        ans=0; vector<int>vis(n);
        fun(0,g,vis);
        return ans;
    }
};