class Solution {
public:
    bool valid(int x,int y, int r, int c){
        return x>=0&&y>=0&&x<r&&y<c;
    }
    void fun(int x, int y, vector<vector<int>>&mat){
           int r=mat.size(); int c=mat[0].size();
         int p=x;int q=y;
        vector<int>temp;
        while(valid(p,q,r,c)){
           temp.push_back(mat[p][q]);
            p++;q++;
        }
        sort(temp.begin(),temp.end());
        p=x;q=y; int ind=0;
         while(valid(p,q,r,c)){
             mat[p][q]=temp[ind];
             ind++;p++;q++;
         }
        
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int r=mat.size(); int c=mat[0].size();
       for(int j=0;j<c;j++){
           fun(0,j,mat);
       } 
        for(int i=1;i<r;i++){
            fun(i,0,mat);
        }
        return mat;
    }
};