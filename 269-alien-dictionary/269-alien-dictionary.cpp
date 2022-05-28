class Solution {
public:
    void fun(string &a, string &b, vector<vector<int>>&g){
        int i=0;int j=0;
        while(i<a.size()&&j<b.size()){
            if(a[i]==b[j]){            
                i++;j++;
            }else {
                g[a[i]-'a'].push_back(b[j]-'a');            
                break;
            }            
        }
        if(j==b.size()&&i<a.size()){
            g[a[0]-'a'].push_back(a[0]-'a');
        }
        
    }
    bool cycle(vector<int>&vis,vector<int>&curr,vector<vector<int>>&g, int node,stack<int>&st){
        vis[node]=1;
        curr[node]=1;
        for(auto a:g[node]){         
          
            if(vis[a]==0){
                if(cycle(vis,curr,g,a,st)) return 1;
            }
             else if(curr[a]==1) return 1;
        }
        curr[node]=0;
        st.push(node);
        return 0;
    }

    string alienOrder(vector<string>& w) {
      vector<int>y(26);
        for(auto a:w){
            for(auto b:a){
                y[b-'a']=1;
            
            }
        }
        vector<vector<int>>g(26);
        for(int i=0;i<w.size();i++){
            for(int j=i+1;j<w.size();j++){
               fun(w[i],w[j],g);
            }
        }
        stack<int>st; 
       vector<int>curr(26); vector<int>vis(26);
        for(int i=0;i<26;i++){
            if(vis[i]==0&&y[i]==1&&cycle(vis,curr,g,i,st)){
              { return {};}
            }
        }
       string ans;
        while(st.size()){
            int c=st.top(); st.pop();
            ans.push_back(c+'a');
        }
        
     for(int i=0;i<26;i++){ 
         if(vis[i]==0&&y[i]==1) {ans.push_back(i+'a');}
     }
        return ans;
    }
};