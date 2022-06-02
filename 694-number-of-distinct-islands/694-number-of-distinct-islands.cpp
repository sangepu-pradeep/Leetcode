class Solution {
public:
int dirx[4]={1,-1,0,0};
    int diry[4]={0,0,-1,1};
    bool fun(vector<pair<int,int>>&a,vector<set<pair<int,int>>>&v){
        int xmn=INT_MAX; 
        int ymn=INT_MAX; 
        for(auto t:a){
            xmn=min(xmn,t.first);   
             ymn=min(ymn,t.second);      
        }
       for(int i=0;i<a.size();i++){
           a[i].first-=xmn;
           a[i].second-=ymn;
       }
        
        for(auto r:v){
            if(r.size()!=a.size())continue;
            bool b=0;
          for(auto p:a){
              if(r.count(p)==0){b=1; break;}
          }
            if(b==0) return 1;
        }
        set<pair<int,int>>temp;
        for(auto p:a){
            temp.insert(p);
        }
        v.push_back(temp);
        return 0;
    }
    void dfs(int x, int y,vector<vector<int>>&grid,vector<pair<int,int>>&temp,vector<vector<int>>&vis){
        vis[x][y]=1; int r=grid.size(); int c=grid[0].size();
        temp.push_back({x,y});
        for(int i=0;i<4;i++){
            int x1=x+dirx[i];
            int y1=y+diry[i];
            if(x1>=0&&y1>=0&&x1<r&&y1<c&&vis[x1][y1]==0&&grid[x1][y1]==1){
                dfs(x1,y1,grid,temp,vis);
            }
        }
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
         vector<set<pair<int,int>>>v;
         int r=grid.size(); int c=grid[0].size();
        int cnt=0; vector<vector<int>>vis(r,vector<int>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(vis[i][j]==0&&grid[i][j]==1){
                    vector<pair<int,int>>temp;
                    dfs(i,j,grid,temp,vis);
                    bool y=fun(temp,v);
                    
                    //cout<<y<<endl;
                    if(y==0) cnt++;
                }
            }
        }
        return cnt;
    }
};