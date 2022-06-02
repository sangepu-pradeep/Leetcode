class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        
        int n=s.size();
        if(n!=t.size()) return 0;
         unordered_map<int,int>mp;
        for(int i=1;i<26;i++){
            if(k>=i)mp[i]=(k-i)/26+1;
            else mp[i]=0;
        }
       
        for(int i=0;i<s.size();i++){
            if(s[i]==t[i]) continue;
            int p=t[i]-s[i];
            if(p<0)p+=26;
       
            if(mp[p]==0)return 0;
            mp[p]--;
        }
        return 1;
    }
};