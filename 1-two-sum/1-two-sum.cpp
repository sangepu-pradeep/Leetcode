class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
  mp[nums[i]].push_back(i);
        }
        sort(nums.begin(),nums.end());
        int i=0; int j=nums.size()-1;
        while(i<=j){
            if(nums[i]+nums[j]>target)j--;
            else if(nums[i]+nums[j]<target)i++;
            else {
                if(nums[i]==nums[j]){
                    return mp[nums[i]];
                }
                else return {mp[nums[i]][0],mp[nums[j]][0]};
            }
        }
        return {};
    }
};