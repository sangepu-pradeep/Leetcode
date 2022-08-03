class Solution {
public:
    bool valid(int k, string &s){
       unordered_map<char,int>vis;
        for(int i=0;i<k;i++){
            vis[s[i]]++;
        }
        bool b=0;
       // for(int i=0;i<26;i++) if(vis[i]>1){b=1;break;}
        for(auto a:vis)if(a.second>1){b=1;break;}
        if(b==0) return 1;
        for(int i=k;i<s.size();i++){
            vis[s[i]]++;
            vis[s[i-k]]--;
            bool b=0;
            for(auto a:vis)if(a.second>1){b=1;break;}
        if(b==0) return 1;
        }
        return 0;
    }
    int lengthOfLongestSubstring(string s) {

      unordered_map<char,int>mp;
        int prev=0; int ans=0;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])){
                prev=max(mp[s[i]]+1,prev);
            }
            ans=max(ans,i-prev+1);
            mp[s[i]]=i;
            
        }
        return ans;
    }
};