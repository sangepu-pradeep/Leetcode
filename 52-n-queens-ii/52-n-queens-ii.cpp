class Solution {
public:
      bool valid(int x, int y, vector<vector<int>>&b){
    
        int r=b.size(); int c=b[0].size();
        for(int i=0;i<r;i++){
            if(b[i][y]) return 0;
        }
        for(int j=0;j<c;j++){
            if(b[x][j]) return 0;
        }
        int dx=-1; int dy=1; int x1=x; int y1=y;
        while(x1>=0&&x1<r&&y1>=0&&y1<c){
            if(b[x1][y1]) return 0;
            x1+=dx;y1+=dy;
        }
        dy=-1;x1=x;y1=y;
        while(x1>=0&&x1<r&&y1>=0&&y1<c){
            if(b[x1][y1]) return 0;
            x1+=dx;y1+=dy;
        }
        return 1;
        
    }
    int fun(int x,int n,vector<vector<int>>&b){
        if(x==n) return 1; int ans=0;
        for(int i=0;i<n;i++){
            if(valid(x,i,b)){
                b[x][i]=1;
                ans+=fun(x+1,n,b);
                b[x][i]=0;
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
        vector<vector<int>>b(n,vector<int>(n));
        return fun(0,n,b);
        
    }
};