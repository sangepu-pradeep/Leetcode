class Solution {
public:
    int parent[1002];
    int find(int a){
        if(parent[a]==a) return a;
        return parent[a]=find(parent[a]);
    }
     void connect(int a, int b){
         int x=find(a); int y=find(b);
         parent[x]=y;
     }
  
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
       for(int i=0;i<=1000;i++)parent[i]=i;
        int p=1; unordered_map<int,string>name;
        unordered_map<string,int>vis;
        for(auto a:acc){
            name[p]=a[0];
            for(int i=1;i<a.size();i++){
                if(vis[a[i]]) connect(vis[a[i]],p);
                vis[a[i]]=p;
            }
            p++;
        }
        unordered_map<string,int>in;
         unordered_map<int,vector<string>>v;
        // for(int i=1;i<p;i++){
        //     int x=find(parent[i]);
        //     v[x]
        // }
       p=1;
        for(auto a:acc){
          
            int x=find(p);
          for(int i=1;i<a.size();i++){
              if(in[a[i]]==0)v[x].push_back(a[i]);
              in[a[i]]=1;
          }
            p++;
        }
        for(auto a:v){
            sort(v[a.first].begin(),v[a.first].end());
        }
        vector<vector<string>>ans;
        for(auto a:v){
            int x=find(a.first);
            vector<string>temp;
            temp.push_back(name[x]);
            for(auto d:a.second)temp.push_back(d);
            ans.push_back(temp);
        }
        return ans;
    }
};