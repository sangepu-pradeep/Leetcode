class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>mp;
        int n=words.size();
        for(auto a:words){
            mp[a]++;
        }
        vector<int>ans;
        int p=words[0].size();
        for(int i=0;i<s.size();i++){
        
            if(i+n*p>s.size())break;
            unordered_map<string,int>temp=mp;bool b=0;
            for(int j=i;j<s.size()&&j<i+n*p;j+=p){
                string t=s.substr(j,p);
                if(temp[t]==0){ b=1;break;}
                temp[t]--;
            }
            if(b==0)ans.push_back(i);
        }
        return ans;
    }
};