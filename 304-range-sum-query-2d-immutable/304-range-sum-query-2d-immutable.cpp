class NumMatrix {
public:
    int prefix[202][202];
    NumMatrix(vector<vector<int>>& m) {
        int r=m.size(); int c=m[0].size();
       for(int i=0;i<r;i++)prefix[i][0]=0;
        for(int i=0;i<r;i++){
            for(int j=1;j<=c;j++){
                prefix[i][j]=prefix[i][j-1]+m[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1;i<=row2;i++){
            int t=prefix[i][col2+1]-prefix[i][col1];
            sum+=t;
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */