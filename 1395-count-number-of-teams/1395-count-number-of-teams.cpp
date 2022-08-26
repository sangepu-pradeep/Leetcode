class Solution {
public:
    int numTeams(vector<int>& r) {
        int n=r.size();
        vector<int>dec(n);
        vector<int>inc(n);
        for(int i=0;i<n;i++){
            int t=r[i];
            for(int j=i+1;j<n;j++){
                if(r[j]>t)inc[i]++;
                else if(r[j]<t)dec[i]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(r[j]>r[i])ans+=inc[j];
                else if(r[j]<r[i])ans+=dec[j];
            }
        }
        return ans;
    }
};