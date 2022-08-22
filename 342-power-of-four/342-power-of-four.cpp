class Solution {
public:
    bool isPowerOfFour(int n) {
      
        if(n<=0) return 0;
        for(int i=0;i<31;i+=2){
            if((n&(~(1<<i)))==0) return 1;
        }
      return 0;
    }
};