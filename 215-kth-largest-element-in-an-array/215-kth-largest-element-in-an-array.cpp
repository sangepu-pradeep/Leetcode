class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int,vector<int>,greater<int>>pq;
        //k=nums.size()-k;
        for(auto a:nums){
           pq.push(a);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};