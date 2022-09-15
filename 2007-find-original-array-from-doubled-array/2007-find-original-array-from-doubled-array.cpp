class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
        vector<int>vis(1e5+1);
        for(auto a:c){
            vis[a]++;
        }
        unordered_map<int,int>mp;
        for(int i=0;i<vis.size()&&(2*i<=1e5);i++){
            if(i==0){
                if(vis[i]%2) return {};
                else mp[0]=vis[i]/2;continue;
            }
           if(vis[2*i]>=vis[i]){
               mp[i]=min(vis[2*i],vis[i]);
               vis[2*i]-=vis[i];
           }else return {};
        }
        vector<int>ans;
         // for(int i=0;i<vis.size();i++){
         //    // if(vis[i]<0) return {};
         //      while(vis[i]--){
         //         ans.push_back(i);
         //      }
         // }
        for(auto a:mp){
            int t=a.second;
            while(t--)ans.push_back(a.first);
        }
        return ans;
    }
};