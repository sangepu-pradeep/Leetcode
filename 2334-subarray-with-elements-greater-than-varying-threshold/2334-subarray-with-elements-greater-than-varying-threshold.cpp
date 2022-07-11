class Solution {
public:
    int fun(int l, int h, int t, vector<int>&nums){
        if(l>h) return -1;
        long len=h-l+1;
        for(int i=l;i<=h;i++){
            long y=(long)nums[i]*len;
            if(y<=(long)t)return max(fun(l,i-1,t,nums),fun(i+1,h,t,nums));
        }
        return h-l+1;
    }
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n=nums.size();
 
        return fun(0,n-1,threshold,nums); 
    }
};