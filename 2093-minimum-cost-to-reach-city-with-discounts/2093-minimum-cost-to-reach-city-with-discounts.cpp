class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& h, int d) {
        vector<vector<pair<int,int>>>g(n);
        for(auto a:h){
            g[a[0]].push_back({a[1],a[2]});
            g[a[1]].push_back({a[0],a[2]});
        }
        vector<vector<int>>vis(n,vector<int>(d+1,INT_MAX));
        auto comp=[](const auto &a,const auto &b){
            return a[0]>b[0];
        };
        priority_queue<array<int,3>,vector<array<int,3>>,decltype(comp)>pq(comp);
        pq.push({0,d,0});
        while(pq.size()){
            auto [cost,dis,i]=pq.top();
            if(i==n-1) break;
            pq.pop();
            for(auto [j,val]:g[i]){
                if(vis[j][dis]>val+cost){
                    vis[j][dis]=val+cost;
                    pq.push({vis[j][dis],dis,j});
                }
                if(dis>0&&vis[j][dis-1]>cost+val/2){
                    vis[j][dis-1]=cost+val/2;
                    pq.push({vis[j][dis-1],dis-1,j});
                }
            }
        }
        if(pq.size()) {
            int ans=INT_MAX;
            for(int i=0;i<=d;i++){
                ans=min(ans,vis[n-1][i]);
            }
            return ans;
        }
        return -1;
    }
};