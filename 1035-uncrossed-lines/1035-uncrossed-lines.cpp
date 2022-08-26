class Solution {
public:
    int dp[502][502];
    int fun(int i, int prev, vector<int>&nums1,vector<int>&nums2){
        if(dp[i][prev]!=-1) return dp[i][prev];
     if(i==nums1.size())return 0;
        int ans=0;
        if(prev==501)prev=-1;
        for(int k=prev+1;k<nums2.size();k++){
            if(nums1[i]==nums2[k]){
               ans=max(ans,1+fun(i+1,k,nums1,nums2)); 
                break;
            }
        }
        if(prev==-1)prev=501;
        ans=max(ans,fun(i+1,prev,nums1,nums2));
        return dp[i][prev]=ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return fun(0,501,nums1,nums2);
    }
};