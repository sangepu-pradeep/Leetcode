class Solution {
public:
    int fun(vector<int>&nums1,vector<int>&nums2, int k){
        int l=INT_MAX; int h=INT_MIN;
        if(nums1.size()){
            l=min(l,nums1[0]);
            h=max(h,nums1.back());
        }
        if(nums2.size()){
            l=min(l,nums2[0]);
            h=max(h,nums2.back());
        }
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            int p=upper_bound(nums1.begin(),nums1.end(),mid)-nums1.begin();
            int q=upper_bound(nums2.begin(),nums2.end(),mid)-nums2.begin();
            if(p+q>k){
                h=mid-1;ans=mid;
            }else{
                l=mid+1;//ans=mid;
            }
            
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         int n1=nums1.size(); int n2=nums2.size();
        double ans=0;
        if((n1+n2)%2==0){
         ans=(double)(fun(nums1,nums2,(n1+n2)/2-1)+fun(nums1,nums2,(n1+n2)/2));
            //cout<<ans<<endl;
            ans=ans/2;
            
        }else {
            ans=fun(nums1,nums2,(n1+n2)/2);
        }
        return ans;
    }
};