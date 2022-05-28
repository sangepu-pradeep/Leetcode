class Solution {
public:
    bool fun(string &node,int n, vector<string>&ans,unordered_map<string,vector<string>>&mp,map<pair<string,string>,int>&vis,string &prev){     
       if(prev!="") vis[{prev,node}]--;;
        ans.push_back(node); 
        if(n==0) return 1;
        for(auto a:mp[node]){
            
            if(vis[{node,a}]&&fun(a,n-1,ans,mp,vis,node)) {return 1;}
        }
       if(prev!="") vis[{prev,node}]++;
         ans.pop_back();
        return 0;
    }
    vector<string> findItinerary(vector<vector<string>>& t) {
        unordered_map<string,vector<string>>mp;
       int n=t.size();  map<pair<string,string>,int>vis;
   
        for(auto a:t){
            mp[a[0]].push_back(a[1]);
            vis[{a[0],a[1]}]++;
        }
        for(auto a:mp){
           // sort(a.second.begin(),a.second.end());
            vector<string>temp=a.second;
            sort(temp.begin(),temp.end());
            mp[a.first]=temp;
        }
        vector<string>ans;
        string node="JFK"; string x="";
        fun(node,n,ans,mp,vis,x);
        return ans;
    }
};