class Solution {
public:
    bool hasAlternatingBits(int n) {
        if(n==1) return 1;
        int prev=n&1;n=(n>>1);
      while(n){
          int b=n&1;
         if(prev==b) return 0; 
          prev=b; n=n/2;
      }  
        return 1;
    }
};