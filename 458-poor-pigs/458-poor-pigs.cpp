class Solution {
public:
    
    int poorPigs(int b, int m, int t) {
         int pigs = 0;
        while (pow(t / m + 1, pigs) < b) {
            pigs += 1;
        }
        return pigs;   
    }
};