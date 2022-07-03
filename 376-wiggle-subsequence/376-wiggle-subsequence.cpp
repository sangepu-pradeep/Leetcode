class Solution {
public:
     int dp[1001][1003][3];
    int fun(int i, int prev, int p, vector<int>&nums){
        if(dp[i][prev][p]!=-1) return dp[i][prev][p];
        if(i==nums.size()) return 0;
        //if(prev==1001) return 1+fun(i+1,i,2,nums);
       if(prev==1001) return max(1+fun(i+1,i,2,nums),fun(i+1,1001,2,nums));
       
        int ans=0;
        //prev==0 negativde, prev=1; positive
        if(nums[i]-nums[prev]>0&&(p==0||p==2)) ans=1+fun(i+1,i,1,nums);
        if(nums[i]-nums[prev]<0&&(p==1||p==2)) ans=1+fun(i+1,i,0,nums);
        ans=max(ans,fun(i+1,prev,p,nums));
       // return ans;
        return dp[i][prev][p]=ans;
    }
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return fun(0,1001,2,nums);
    }
};