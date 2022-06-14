class Solution {
public:
    vector<int> fun(vector<vector<int>>&mat,int x, int y, int r, int c){
        vector<int>ans;
       while(x>=0&&y>=0&&x<r&&y<c){
           ans.push_back(mat[x][y]);
           x++;y--;
       } 
        return ans;
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
         int r=mat.size(); int c=mat[0].size();
        vector<int>ans; bool b=1;
        for(int j=0;j<c;j++){
            auto a=fun(mat,0,j,r,c);
            if(b) reverse(a.begin(),a.end());
            for(auto t:a) ans.push_back(t);
            b=b^1;
        }
        for(int i=1;i<r;i++){
           auto a= fun(mat,i,c-1,r,c);
            if(b) reverse(a.begin(),a.end());
            for(auto t:a) ans.push_back(t);
            b=b^1;
        }
        return ans;
    }
};