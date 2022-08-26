class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_map<int,vector<string>>mp;
        
        auto comp=[](auto &a,auto &b){
            return a>b;
        };
        for(int i=1;i<=1e9;i*=2){
            string p=to_string(i);
            sort(p.begin(),p.end(),comp);
            mp[p.size()].push_back(p);
        }
        string t=to_string(n);
        sort(t.begin(),t.end(),comp);
        for(auto a:mp[t.size()]){
            if(a==t) return 1;
        }
        return 0;
    }
};