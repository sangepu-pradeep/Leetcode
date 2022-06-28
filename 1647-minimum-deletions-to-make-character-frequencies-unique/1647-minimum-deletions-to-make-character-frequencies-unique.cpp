class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        for(auto a:s) mp[a]++;
         vector<int>v;
        for(auto a:mp) v.push_back(a.second);
        unordered_map<int,int>h; int cnt=0;
      for(auto a:v){
          while(a&&h[a]){a--;cnt++;}
          h[a]=1;
      }
        return cnt;
    }
};