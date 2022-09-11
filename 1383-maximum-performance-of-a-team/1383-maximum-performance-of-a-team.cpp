class Solution {
public:
    int mod=1e9+7;
    int maxPerformance(int n, vector<int>& sp, vector<int>& e, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({e[i],sp[i]});
        }
        sort(v.begin(),v.end());
        auto comp=[](const auto &a,const auto &b){
            return a>b;
        };
        priority_queue<int,vector<int>,decltype(comp)>pq(comp); long sum=0;
        long ans=0;
        for(int i=n-1;i>=n-k;i--){
            pq.push(v[i].second);
            sum+=v[i].second;
            long t=(long)sum*v[i].first;
            if(ans<t)ans=t;
        }
 //    long long ans= (long)v[n-k].first*sum;
        for(int i=n-k-1;i>=0;i--){
          
            if(pq.top()<v[i].second){
                sum-=pq.top();sum+=v[i].second;
                pq.pop(); pq.push(v[i].second);
                if(ans<(long)v[i].first*sum)ans=(long)v[i].first*sum;
            }else {
                long long t=(long)v[i].first*sum;
                if(ans<t)ans=t;
            }
      
        }
        ans=ans%mod;
        return ans;
    }
};