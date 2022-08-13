class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        int r=m.size(); int c=m[0].size();
       int l=m[0][0]; int h=m[r-1][c-1]; int ans=m[0][0];
        while(l<=h){
            int mid=(l+h)/2;
            int t=0;
            for(int i=0;i<r;i++){
                t+=(lower_bound(m[i].begin(),m[i].end(),mid)-m[i].begin());
            }
        
            if(t<k){ans=mid;l=mid+1;}
            else h=mid-1;
        }
        return ans;
    }
};