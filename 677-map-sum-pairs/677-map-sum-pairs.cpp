class MapSum {
public:
    unordered_map<string,int>mp;
    unordered_map<string,int>w;
    MapSum() {
        mp={};
    }
    
    void insert(string key, int val) {
        string temp; int t=0;
          t=w[key];
       
        for(int i=0;i<key.size();i++){
            temp.push_back(key[i]);
            mp[temp]+=val;
            mp[temp]-=t;
        }
        w[key]=val;
    }
    
    int sum(string prefix) {
        return mp[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */