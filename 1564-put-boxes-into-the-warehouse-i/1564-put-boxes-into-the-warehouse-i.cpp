class Solution {
public:
    int fun(int a, vector<int>&mn, int last){
        int l=0; int h=last; int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(mn[mid]>=a) {ans=mid;l=mid+1;}
            else h=mid-1;
        }
        return ans;
    }
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& w) {
      sort(boxes.begin(),boxes.end());
        vector<int>mn;
         int t=INT_MAX;
        for(auto a:w){
           t=min(t,a);
            mn.push_back(t);
        }
        int l=w.size()-1;int cnt=0;
        for(auto a:boxes){
            int d=fun(a,mn,l);
            if(d==-1) return cnt;
            l=d-1; cnt++;
        }
        return cnt;
    }
};