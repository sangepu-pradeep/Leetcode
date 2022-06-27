class Solution {
public:
    int minPartitions(string n) {
        int ans=0;
        for(auto a:n){
            int p=a-'0';
            ans=max(ans,p);
        }
        return ans;
    }
};