class Solution {
public:
   // int vis[41][41][1604];
    int dirx[4]={1,-1,0,0};
    int diry[4]={0,0,1,-1};
    bool valid(int x, int y, int r, int c){
        return x>=0&&y>=0&&x<r&&y<c;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
     int r=grid.size(); int c=grid[0].size(); 
        vector<vector<vector<int>>>vis(r+1,vector<vector<int>>(c+1,vector<int>(k+1,INT_MAX)));
       // d,x,y,k
        auto comp=[](const auto &a, const auto &b){
            return a[0]>b[0];
        };
        priority_queue<array<int,4>,vector<array<int,4>>,decltype(comp)>pq(comp);
        pq.push({0,0,0,k}); vis[0][0][k]=0;
        while(pq.size()){
            auto a=pq.top(); pq.pop();
            for(int i=0;i<4;i++){
                int x=a[1]+dirx[i]; int y=a[2]+diry[i];
                if(valid(x,y,r,c)){
                    if(grid[x][y]==1&&a[3]>0&&vis[x][y][a[3]-1]>1+a[0]){
                        vis[x][y][a[3]-1]=1+a[0];
                        pq.push({1+a[0],x,y,a[3]-1});
                    }
                    else if(grid[x][y]==0&&vis[x][y][a[3]]>1+a[0]){
                        vis[x][y][a[3]]=1+a[0];
                        pq.push({1+a[0],x,y,a[3]});
                    }
                }
            }
            
        }
        int ans=INT_MAX;
       for(int i=0;i<=k;i++){
           ans=min(ans,vis[r-1][c-1][i]);
       }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};