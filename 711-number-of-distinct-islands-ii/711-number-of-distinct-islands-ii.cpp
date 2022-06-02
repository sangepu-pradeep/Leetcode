class Solution {
public:
     int dirx[4]={1,-1,0,0};
    int diry[4]={0,0,-1,1};
    
    void base(vector<pair<int,int>>&a){
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
    }
    void solve(unordered_map<int,set<set<pair<int,int>>>>&v,vector<pair<int,int>>&a){
        auto a1=a;
        for(int i=0;i<a1.size();i++){
            a1[i].first*=-1;
        }
        base(a1);
        auto a2=a;
        for(int i=0;i<a2.size();i++){
            a2[i].second*=-1;
        }
        base(a2);
        auto a3=a;
        for(int i=0;i<a3.size();i++){
            a3[i].second*=-1;
            a3[i].first*=-1;
        }
        base(a3);
         set<pair<int,int>>temp,temp1,temp2,temp3;
        for(auto p:a){
            temp.insert(p);
        }
         for(auto p:a1){
            temp1.insert(p);
        }
         for(auto p:a2){
            temp2.insert(p);
        }
         for(auto p:a3){
            temp3.insert(p);
        }
      v[a.size()].insert(temp);  
        v[a.size()].insert(temp1);  
        v[a.size()].insert(temp2); 
          v[a.size()].insert(temp3); 
    }
    bool fun(vector<pair<int,int>>&a,unordered_map<int,set<set<pair<int,int>>>>&v){
       
        base(a);
        for(auto r:v[a.size()]){
            if(r.size()!=a.size())continue;
            bool b=0;
          for(auto p:a){
              if(r.count(p)==0){b=1; break;}
          }
            if(b==0) return 1;
        }
     
       
        auto a1=a;//90
        for(int i=0;i<a1.size();i++){
            swap(a1[i].first,a1[i].second);
           a1[i].first*=-1;       
        }
        base(a1);
        auto a2=a;
    for(int i=0;i<a2.size();i++){
            swap(a2[i].first,a2[i].second);
           a2[i].second*=-1;       
        }
        base(a2);
        // auto a3=a;
        //  for(int i=0;i<a3.size();i++){
        //     swap(a3[i].first,a3[i].second);  
        //        a3[i].first*=-1;  
        //            a3[i].second*=-1;  
        // }
        // base(a3);
          solve(v,a);
        solve(v,a1);
        solve(v,a2);
       // solve(v,a3);
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
    int numDistinctIslands2(vector<vector<int>>& grid) {
      //   set<set<pair<int,int>>>v;
        unordered_map<int,set<set<pair<int,int>>>>v;
         int r=grid.size(); int c=grid[0].size();
        int cnt=0; vector<vector<int>>vis(r,vector<int>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(vis[i][j]==0&&grid[i][j]==1){
                    vector<pair<int,int>>temp;
                    dfs(i,j,grid,temp,vis);
                    bool y=fun(temp,v); 
                    // if(i==2&&j==4){
                    //     for(auto a:v){
                    //         for(auto p:a){
                    //             cout<<p.first<<" "<<p.second<<endl;
                    //         }
                    //         cout<<endl;
                    //     }
                    // }
                    if(y==0) cnt++;
                }
            }
        }
        return cnt;
    }
};