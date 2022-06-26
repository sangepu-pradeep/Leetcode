class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n=c.size()-k;
         vector<int>prefix(c.size()+1);
        for(int i=1;i<=c.size();i++){
            prefix[i]=prefix[i-1]+c[i-1];
        }
      int mn=INT_MAX;

        for(int i=0;i<c.size();i++){
            if(i+1-n>=0){
                mn=min(mn,prefix[i+1]-prefix[i+1-n]);
            }
        }
        return prefix[c.size()]-mn;
    }
};