class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum=0;
        for(auto a:nums){
            sum+=a;
        }
        long n=nums.size();
        int p=(n*(n+1))/2-sum;
        return p;
    }
};