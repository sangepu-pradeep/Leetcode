class Solution {
public:
    
 vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n+1,0),V1,V2;
     for(auto &edge:edges){
         if(parent[edge[1]]==0){
           parent[edge[1]]=edge[0];  
         }
         else{
             V1={parent[edge[1]],edge[1]};
            V2=edge; 
             edge[1]=0;
         }
     }
    
     for(int i=1;i<=n;i++){
        parent[i]=i; 
     }
 
     for(auto &edge:edges){
         if(edge[1]==0) continue;
         
         int u = edge[0], v = edge[1], pu = root(parent, u);
            // Now every node only has 1 parent, so root of v is implicitly v
            if (pu == v) {
                if (V1.empty()) return edge;
                return V1;
            }
            parent[v] = pu;
        }
        return V2;
     }
  
     int root(vector<int> &parent, int k){
        
        if(parent[k]!=k) 
           
         parent[k]=root(parent,parent[k]);
            return parent[k];
    }
};