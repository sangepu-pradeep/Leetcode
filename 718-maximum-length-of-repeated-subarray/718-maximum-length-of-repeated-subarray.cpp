class Solution {
public:
    int dp[1001][1001];
    int fun(int i, int j, vector<int>&nums1, vector<int>&nums2){
        if(i==nums1.size()||j==nums2.size()) return 0;
      if(dp[i][j]!=-1) return dp[i][j];
        int p=i; int q=j;
        // while(p<nums1.size()&&q<nums2.size()){
        //     if(nums1[p]==nums2[q]){
        //         p++;q++;
        //     }
        // }
        if(nums1[i]==nums2[j]){
            return dp[i][j]=1+fun(i+1,j+1,nums1,nums2);
        }
        return dp[i][j]=0;
    }
        
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        int mx=0;
     for(int i=0;i<nums1.size();i++){
         for(int j=0;j<nums2.size();j++){
             mx=max(mx,fun(i,j,nums1,nums2));
         }
     }
        return mx;
    }
};