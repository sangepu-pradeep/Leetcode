class Solution {
public:
    void dfs(int node,vector<int>&e,vector<int>&vis,stack<int>&st){
        vis[node]=1;
        if(e[node]!=-1&&vis[e[node]]==0) dfs(e[node],e,vis,st);
        st.push(node);
    }
    int ans;
   void fun(int node,vector<int>&e,int d, vector<int>&vis,unordered_map<int,int>&curr){
       vis[node]=d; curr[node]=d;
        if(e[node]!=-1&&curr[e[node]]>0){
            ans=max(ans,d-curr[e[node]]+1);
        } 
       if(e[node]!=-1&&vis[e[node]]==0){
           fun(e[node],e,d+1,vis,curr);
       }
    }
    int longestCycle(vector<int>& e) {
        int n=e.size();
        stack<int>st;
        vector<int>vis(n);
        for(int i=0;i<n;i++){
            if(vis[i]==0)dfs(i,e,vis,st);
        }
       ans=-1; vector<int>vis1(n);
       // fun(0,e,1,vis1);
        while(st.size()){
            if(vis1[st.top()]) {st.pop();continue;}
    unordered_map<int,int>curr;
         // vector<int>curr(n);  
            fun(st.top(),e,1,vis1,curr);
            //cout<<st.top()<<" "<<ans<<endl;
          
        }
        return ans;
    }
};