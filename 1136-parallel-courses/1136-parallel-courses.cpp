class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& r) {
        vector<vector<int>>g(n); vector<int>in(n);
        for(auto a:r){
            --a[0];--a[1];
           g[a[0]].push_back(a[1]);
            in[a[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(in[i]==0)q.push(i);
        }
        int cnt=0; int ans=0;
        while(q.size()){
            int sz=q.size();
            int s=q.size();
           while(s--) {
               int a=q.front();
            q.pop();
            for(auto t:g[a]){
                in[t]--;
               // if(in[t]<0) return -1;
                if(in[t]==0)q.push(t);
            }
           }
            cnt+=sz;
            ans++;
        }
       // cout<<cnt<<" "<<n;
        if(cnt==n) return ans;
     
    return -1;
    }
};