class Solution {
public:
   
    int maxPoints(vector<vector<int>>& p) {
        int ans=1;
        long double r=1e9;
        for(int i=0;i<p.size();i++){
            unordered_map<long double,int>mp;
            for(int j=i;j<p.size();j++){
                if(i==j)continue;
                 long double t;
                if( (long double)p[j][0]- (long double)p[i][0]==0)t=1e9;
               else t=( (long double)p[j][1]- (long double)p[i][1])/( (long double)p[j][0]- (long double)p[i][0]);
                mp[t]++;               
            }
            for(auto a:mp){
                ans=max(ans,a.second+1);
            }
        }
        return ans;
    }
};