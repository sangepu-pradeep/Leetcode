class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1); stack<int>st;
        for(int i=0;i<n;i++){
            if(st.size()&&nums[i]>nums[st.top()]){
                while(st.size()&&nums[i]>nums[st.top()]){
                    int t=st.top();
                    ans[t]=nums[i];st.pop();
                }
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            if(st.size()&&nums[i]>nums[st.top()]){
                while(st.size()&&nums[i]>nums[st.top()]){
                    int t=st.top();
                    ans[t]=nums[i];st.pop();
                }
            }
        }
        return ans;
    }
};