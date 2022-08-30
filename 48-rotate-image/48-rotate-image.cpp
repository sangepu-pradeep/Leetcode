class Solution {
public:
    void rotate(vector<vector<int>>& m) {
      // i, j-> j,r-i-1
        // r-i-1, r-j-1
        //     r-j-1, i
        int r=m.size(); int c=m[0].size();
            int i=0;int f=0;int p=1;
        int l=0; int h=r-1;
        while(i<r/2){
            for( int j=f;j<r-f-1;j++){
                int t=m[i][j];
                m[i][j]=m[r-j-1][i];// 
                m[r-j-1][i]=m[r-i-1][r-j-1];
                m[r-i-1][r-j-1]=m[j][r-i-1];
                m[j][r-i-1]=t;
            }
            i++;l++;h--;f++;
        }
        return ;
       
    }
};