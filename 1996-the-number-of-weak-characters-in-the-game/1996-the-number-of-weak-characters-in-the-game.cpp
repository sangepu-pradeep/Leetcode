class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        multiset<int>st;
        auto comp=[](auto &a,auto &b){
            return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
        };
        sort(p.begin(),p.end(),comp);
        int ans=0;
        int mx=0;
        for(int i=p.size()-1;i>=0;i--){
           if(mx>p[i][1]) ans++;
            mx=max(mx,p[i][1]);
        }
        return ans;
    }
};