class Solution {
public:
    
    vector<int> shortestDistanceColor(vector<int>& c, vector<vector<int>>& q) {
       vector<vector<int>>dis(c.size()+1,vector<int>(4,INT_MAX));
     vector<int>prev(4,INT_MAX);
        for(int i=0;i<c.size();i++){
           for(int j=1;j<=3;j++){
               if(j==c[i]) {dis[i][j]=0;prev[j]=i;continue;}
               if(prev[j]!=INT_MAX){dis[i][j]=i-prev[j];}
           }
        }
        for(int i=1;i<=3;i++)prev[i]=INT_MAX;
        for(int i=c.size()-1;i>=0;i--){
            for(int j=1;j<=3;j++){
                 if(j==c[i]) {dis[i][j]=0;prev[j]=i;continue;}
               if(prev[j]!=INT_MAX){dis[i][j]=min(prev[j]-i,dis[i][j]);}
            }
        }
        vector<int>ans;
        for(auto a:q){
         int p=dis[a[0]][a[1]];
            if(p==INT_MAX)ans.push_back(-1);
            else ans.push_back(p);
        }
        return ans;
      
    }
};