class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int temp1=0; int temp2=0;
        vector<int>nums(m+n); int temp=0;
        while(temp1<m||temp2<n){
            if(temp1<m&&temp2<n){
                if(nums1[temp1]<nums2[temp2]){
                    nums[temp]=nums1[temp1];
                    temp1++;temp++;
                }else{
                    nums[temp]=nums2[temp2];
                    temp2++;temp++;
                }
            }else{
                if(temp1<m){
                     nums[temp]=nums1[temp1];
                    temp1++;temp++;
                }else{
                    nums[temp]=nums2[temp2];
                    temp2++;temp++;
                }
            }
        }
        nums1=nums;
    }
};