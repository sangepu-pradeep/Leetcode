class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& m) {
        int r=m.size();int c=m[0].size();
        vector<vector<int>>ans(c,vector<int>(r));
        for(int i=0;i<c;i++){
            for(int j=0;j<r;j++){
                ans[i][j]=m[j][i];
            }
        }
        return ans;
    }
};