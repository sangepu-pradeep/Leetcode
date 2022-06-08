class Solution {
public:
   bool fun(string &s){
       int i=0;int j=s.size()-1;
       while(i<j){
           if(s[i]==s[j]){
               i++;j--;
           }else return 0;
       }
       return 1;
   }
    int removePalindromeSub(string s) {
        if(s=="") return 0;
        if(fun(s)) return 1;
        return 2;
        
    }
};