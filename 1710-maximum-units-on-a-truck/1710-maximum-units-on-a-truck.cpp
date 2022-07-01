class Solution {
public:
    int maximumUnits(vector<vector<int>>& b, int t) {
        auto comp=[](auto &a,auto &b){
            return a[1]>b[1];
        };
        sort(b.begin(),b.end(),comp);
        int d=t; int ans=0;
      for(auto a:b){
          if(d==0) return ans;
          ans+=(a[1]*min(d,a[0]));
          d-=min(d,a[0]);
      }
        return ans;
    }
};