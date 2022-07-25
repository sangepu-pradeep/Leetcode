class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int n=nums.size();
      int p=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(p==nums.size()||nums[p]!=target) return {-1,-1};
        int q=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        return {p,q-1};
    }
};