class HitCounter {
public:
    unordered_map<int,int>mp;
    HitCounter() {
        mp={};
    }
    
    void hit(int timestamp) {
        mp[timestamp]++;
    }
    
    int getHits(int t) {
        int ans=0;
        for(int i=t-299;i<=t;i++){
            ans+=mp[i];         
        }
        return ans;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */