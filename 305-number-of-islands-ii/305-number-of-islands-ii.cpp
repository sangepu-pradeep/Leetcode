class Solution {
public:
     int r,c;
    int hash(int x, int y){
        return c*x+y;
    }
    int dirx[4]={1,-1,0,0};
    int diry[4]={0,0,-1,1};
    int parent[10005];
    int cnt;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void connect(int a,int b){
        int x=find(a); int y=find(b);
        if(x==y) return;
        cnt--;
        parent[x]=y;
    }
        
    vector<int> numIslands2(int m, int n, vector<vector<int>>& p) {
         r=m;c=n;
        vector<vector<int>>b(m,vector<int>(n));
        for(int i=0;i<10005;i++)parent[i]=i;
          cnt=0;vector<int>ans;
      for(auto a:p){
        
         if(b[a[0]][a[1]]==0){
               cnt++;
          for(int i=0;i<4;i++){
              int x1=a[0]+dirx[i]; int y1=a[1]+diry[i];
              if(x1<m&&y1<n&&x1>=0&&y1>=0&&b[x1][y1]==1){
                  connect(hash(x1,y1),hash(a[0],a[1]));
              }
          }
         }
          b[a[0]][a[1]]=1;
          ans.push_back(cnt);
      }
        return ans;
    }
};