class Solution {
public:
    int fun(string &s){
        int i=0;int j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                char c=s[i];
                while(i<=j&&s[i]==c)i++;
                while(i<=j&&s[j]==c)j--;
            }else return j-i+1;
        }
        if(i==j) return 1;
        return 0;
    }
    int minimumLength(string s) {
       return fun(s); 
    }
};