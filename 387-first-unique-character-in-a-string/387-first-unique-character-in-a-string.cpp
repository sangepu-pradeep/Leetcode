class Solution {
public:
    int firstUniqChar(string s) {
  unordered_map<char,int>mp;
        for(auto a:s){
        mp[a]++;
        }
        unordered_set<char>st;
        for(auto a:mp){
            if(a.second==1) st.insert(a.first);
        }
        int ans=-1;
        for(int i=0;i<s.size();i++){
            if(st.count(s[i])) return i;
        }
        return -1;
    }
};