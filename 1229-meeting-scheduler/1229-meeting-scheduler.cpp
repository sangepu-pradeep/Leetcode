class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& s1, vector<vector<int>>& s2, int d) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
       int i=0; int j=0;
        while(i<s1.size()&&j<s2.size()){
           if(s2[j][1]<s1[i][0]){
               j++;continue;
           }
            else if(s1[i][1]<s2[j][0]){
                i++; continue;
            }
            int s=max(s1[i][0],s2[j][0]);
            int e=min(s1[i][1],s2[j][1]);
            if(e-s>=d) return {s,s+d};
            if(e==s1[i][1]) i++;
            else j++;
        }
        return {};
    }
};