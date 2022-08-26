class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
      vector<int>dp;
    
       unordered_map<int,int>mp;
        for(auto a:arr){
            if(mp.count(a-diff)){
                mp[a]=mp[a-diff]+1;
            }else mp[a]=1;
        }
        int mx=1;
        for(auto a:mp){
            mx=max(mx,a.second);
        }
        return mx;
    }
};