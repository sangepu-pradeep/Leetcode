class Solution {
public:
    bool valid(int a){
        return a>=0&&a<=9;
    }
    vector<int>fun(int prev, int sz, int k){
        if(sz==0) return {0};
        vector<int>ans;
        int a=(prev-k);
        int b=(prev+k);
        if(valid(a)){
            int t=pow(10,sz-1)*a;
            auto d=fun(a,sz-1,k);
            for(auto r:d){
                ans.push_back(t+r);
            }
        }
         if(a!=b&&valid(b)){
            int t=pow(10,sz-1)*b;
            auto d=fun(b,sz-1,k);
            for(auto r:d){
                ans.push_back(t+r);
            }
        }
        return ans;
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans; int y=pow(10,n-1);
        for(int i=1;i<=9;i++){
            auto t=fun(i,n-1,k);
            int e=y*i;
            for(auto a:t)ans.push_back(a+e);
        }
        return ans;
    }
};