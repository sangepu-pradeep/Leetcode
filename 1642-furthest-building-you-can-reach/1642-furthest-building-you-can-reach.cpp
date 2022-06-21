class Solution {
public:
  
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=1;i<h.size();i++){
            int t=h[i]-h[i-1];
            if(t>0){
               if(pq.size()==l){
                   pq.push(t);
                   int g=pq.top(); pq.pop();
                   if(g>b) return i-1;
                   b-=g;
               }else pq.push(t);
            }
        }
        return h.size()-1;
    }
};