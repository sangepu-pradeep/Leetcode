class Solution {
public:
    int fun(int ind, vector<int>&bal){
        if(ind==bal.size()) return 0;
        if(bal[ind]==0) return fun(1+ind,bal); int ans=INT_MAX;;
        for(int i=ind+1;i<bal.size();i++){
            if(bal[i]*bal[ind]>=0)continue;
            int ii=bal[i]; int iind=bal[ind];
               bal[i]+=bal[ind];bal[ind]=0;
            ans=min(1+fun(ind+1,bal),ans);
            bal[i]=ii; bal[ind]=iind;
        }
        return ans;
    }
    int minTransfers(vector<vector<int>>& t) {
        int n=12;
        vector<int>bal(n);
        for(auto a:t){
            bal[a[0]]-=a[2];
            bal[a[1]]+=a[2];
        }
        
        return fun(0,bal);
    }
};