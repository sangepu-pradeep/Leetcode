class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=1;i<nums.size();i++){
            int l=lower_bound(nums.begin(),nums.begin()+i-1,target-nums[i])-nums.begin();
            if(nums[l]==target-nums[i]) return {l+1,i+1};
        }
        return {};
    }
};