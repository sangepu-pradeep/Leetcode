class Solution {
public:
    int maxArea(int r, int c, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        long ans=0;
      int mh=0; int prev=0;
        for(auto a:h){
            mh=max(a-prev,mh);
            prev=a;
        }
        mh=max(r-prev,mh);
        int mv=0; prev=0;
        for(auto a:v){
            mv=max(mv,a-prev);
            prev=a;
        }
        mv=max(c-prev,mv);
        long mod=1e9+7;
       
         ans=((long)mv*(long)mh)%mod;
        return ans;
        
    }
};