class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;vector<int>temp(nums2.size(),-1);
        for(int i=0;i<nums2.size();i++){
            if(st.size()&&nums2[st.top()]<nums2[i]){
                while(st.size()&&nums2[st.top()]<nums2[i]){
                     int p=st.top();st.pop();
                    temp[p]=nums2[i];
                }           
            }
                st.push(i);
        }
        unordered_map<int,int>mp;
       for(int i=0;i<nums2.size();i++){
         mp[nums2[i]]=i;  
       }
        vector<int>ans;;
        
        for(auto a:nums1){
            int ind=mp[a];
            ans.push_back(temp[ind]);
        }
        return ans;
    }
};