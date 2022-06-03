class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
       stack<int>st;  int start=nums.size(); int end=0;
           int mx=nums[0];st.push(0);
          for(int i=1;i<nums.size();i++){
              if(mx>nums[i])end=i;
              if(st.size()&&nums[i]<nums[st.top()]){
                  start=i;
                 while(st.size()&&nums[i]<nums[st.top()]){
                     st.pop();
                 } 
              }
             if(start==nums.size()) st.push(i);
              mx=max(mx,nums[i]);
          }
    //    cout<<st.top();
        start=st.size()>0?st.top()+1:0;
       // cout<<start;
        if(end==0) return 0;
        return end-start+1;
    }
};