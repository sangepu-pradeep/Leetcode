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
    int fun(int x, vector<vector<int>>&b, vector<vector<string>>&ans){
        if(x==b.size()) {
       
            vector<string>temp;
            for(int i=0;i<b.size();i++){
                string t;
                for(int j=0;j<b.size();j++){
                    if(b[i][j]==0)t+=".";
                    else t+="Q";
                }
                temp.push_back(t);
                    
            }
            ans.push_back(temp);
            return 1; 
        }int n=b.size();
        for(int i=0;i<n;i++){
            if(valid(x,i,b)){
                b[x][i]=1;
               int bl=fun(x+1,b,ans);
               // if(bl==1) return 1;
                b[x][i]=0;
            }
        }
        return 0;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>b(n,vector<int>(n));
            vector<vector<string>>ans;
        fun(0,b,ans);
    
       return ans;
    }
};