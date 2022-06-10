class Solution {
public:
    bool solve(unordered_map<char,int>&vis){
        for(auto a:vis){
            if(a.second>1) return 0;
        }
        return 1;
    }
    bool fun(int k, string &s){
   unordered_map<char,int>vis;
        for(int i=0;i<k;i++){
            vis[s[i]]++;
        }
        if(solve(vis)) return 1;
        for(int i=k;i<s.size();i++){
            vis[s[i-k]]--;
              vis[s[i]]++;
                if(solve(vis)) return 1;
        }
        return 0;
    }
    int lengthOfLongestSubstring(string s) {

        if(s=="") return 0;
        int l=1; int h=s.size(); int ans=1;
     //   return fun(2,s);
        while(l<=h){ 
            int mid=(l+h)/2;
            if(fun(mid,s)) {l=mid+1;ans=mid;}
            else h=mid-1;
        }
        return ans;
    }
};