class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto a:arr){
            if(a%2==0&&mp[a/2]==1) return 1;
            else if(mp[2*a]) return 1;
            mp[a]=1;
        }
        return 0;
    }
};