class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size()!=s.size()) return 0;
        vector<int>vis(26);
        for(auto a:s){
            vis[a-'a']++;
        }
        for(auto a:t){
            if(vis[a-'a']==0) return 0;
            vis[a-'a']--;
        }
        return 1;
    }
};