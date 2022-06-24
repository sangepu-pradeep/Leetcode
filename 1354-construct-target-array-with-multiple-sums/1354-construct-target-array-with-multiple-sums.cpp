class Solution {
public:
    bool isPossible(vector<int>& target) {
      priority_queue<int>pq;
            long sum=0;
        for(auto a:target) {pq.push(a);sum+=a;}
    
        while(pq.top()>1){
           int t=pq.top(); pq.pop();
              long rm=sum-t;
              int h=t-rm;
            if(h>rm&&rm!=0)h=h-(rm*(h/rm-1));
            if(h<1) return 0;
            if(h>=t) return 0;
            sum=sum-t+h;
            pq.push(h);
        }
   
        if(pq.top()<1) return 0;
       
        // while(pq.size()){
        //     if(pq.top()!=1) return 0;
        //     pq.pop();
        // }
        return 1;
    }
};