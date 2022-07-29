class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
     vector<string>ans;
        for(auto a:words){
             unordered_map<char,char>mp;
        unordered_map<char,char>r; bool b=0;
           for(int i=0;i<a.size();i++){
               if(mp.count(a[i])==0&&r.count(p[i])==0){
                   mp[a[i]]=p[i]; r[p[i]]=a[i];
               }else if(mp.count(a[i])&&r.count(p[i])&&mp[a[i]]==p[i]&&r[p[i]]==a[i]){
                   
               }
              else {b=1;break;}
           }
            if(b==0) ans.push_back(a);
        }
        return ans;
    }
};