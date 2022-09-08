class Solution {
public:
    void fun(string &a,unordered_map<string,int>&mp){
               string temp; int i=0;
           while(i<a.size()&&isdigit(a[i])){
               temp.push_back(a[i]);i++;
           } 
          i++;
        int t=stoi(temp);
          string s;
        for(int j=a.size();j>=i;j--){
          
             while(j>=i&&a[j]!='.'){
                 s.push_back(a[j]);j--;
             }
            auto y=s;
            
            reverse(y.begin(),y.end());
            mp[y]+=t;
            if(j>=0){
                s.push_back('.');
            }
        }
    }
    vector<string> subdomainVisits(vector<string>& cpd) {
        unordered_map<string,int>mp;
        for(auto a:cpd){
            fun(a,mp);
        }
        vector<string>ans;
        for(auto a:mp){
            string p=a.first; 
            int t=a.second;
            string tt=to_string(t);
            string temp=tt+" "+p;
            ans.push_back(temp);
        }
        return ans;
    }
};