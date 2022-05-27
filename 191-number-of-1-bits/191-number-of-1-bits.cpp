class Solution {
public:
    int hammingWeight(uint32_t n) {
        int e=0; int cnt=0;
     while(n){
       
         n=n^(n&(-n));
           cnt++;
     }
        return cnt;
    }
};