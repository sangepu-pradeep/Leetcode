class Solution {
public:
    int minSetSize(vector<int>& arr) {
   unordered_map<int,int>mp;
        
        for(auto a:arr){
            mp[a]++;
        }
        vector<int>v;
        for(auto a:mp){
            v.push_back(a.second);
        }
        sort(v.begin(),v.end(),greater<int>());
        int n=arr.size(); int temp=0; int cnt=0;
       for(auto a:v){  
           
           temp+=a;
         cnt++;
           if(temp>=n/2) return cnt;
       }
        return cnt;
    }
};