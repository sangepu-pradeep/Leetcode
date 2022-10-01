class Solution {
public:
    int fun(vector<int>&nums1,vector<int>&nums2, int k){
        
        
        int l=min(nums1.size()?nums1[0]:INT_MAX,nums2.size()?nums2[0]:INT_MAX);
        int h=max(nums1.size()?nums1.back():INT_MIN,nums2.size()?nums2.back():INT_MIN);
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            int l1=lower_bound(nums1.begin(),nums1.end(),mid)-nums1.begin();
          int l2=lower_bound(nums2.begin(),nums2.end(),mid)-nums2.begin(); 
            if(l1+l2<=k){
             l=mid+1;ans=mid;
            }
            else    { h=mid-1;   }
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int l=nums1.size()+nums2.size();
        if(l%2){
         return fun(nums1,nums2,l/2);
            
        }
       double ans= fun(nums1,nums2,l/2-1)+fun(nums1,nums2,l/2);
        ans/=2;
         return ans;
    }
};