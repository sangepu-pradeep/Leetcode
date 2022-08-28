class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& mat, int kk) {
        int r=mat.size(); int c=mat[0].size();
         for(int i=0;i<r;i++){
             for(int j=1;j<c;j++){
                 mat[i][j]+=mat[i][j-1];
             }
         }
        int mx=INT_MIN;
        for(int i=0;i<c;i++){
            for(int j=i;j<c;j++){
                int sum=0;set<int>st;st.insert(0);
                for(int k=0;k<r;k++){
                  int t=0;
                    // for(auto a:st)cout<<a<<"  ";
                    // cout<<endl;
                    if(i>=1){
                        t=mat[k][j]-mat[k][i-1];
                    }else t=mat[k][j];
                    sum+=t;
                    auto a=st.lower_bound(sum-kk);
                    int p=(*a);
                    if(sum-p<=kk&&st.count(p)){
                      
                        mx=max(mx,sum-p);
                    }
                    st.insert(sum);
                }
                
            }
        }
        return mx;
    }
};