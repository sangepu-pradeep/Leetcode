class Solution {
public:
    int numRabbits(vector<int>& answers) {
       unordered_map<int,pair<int,int>>mp;
        for(auto a:answers){
            if(mp.count(a+1)) {
                if(mp[a+1].first==a+1)
                { mp[a+1].first=1;
                mp[a+1].second++;
                }
                else mp[a+1].first++;
            }
            else {
                mp[a+1]={1,1};
            }
        }
        int ans=0;
        for(auto a:mp){
            ans+=(a.second.second)*(a.first);
        }
        return ans;
    }
};