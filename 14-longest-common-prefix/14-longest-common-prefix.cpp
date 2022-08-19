class Solution {
public:
    string fun(string &a,string &b){
        int i=0;int j=0; string temp;
        while(i<a.size()&&j<b.size()){
            if(a[i]!=b[j]) return temp;
            temp.push_back(a[i]);
            i++;j++;
        }
        return temp;
    }
    string longestCommonPrefix(vector<string>& s) {
       string temp=s[0];
        for(int i=1;i<s.size();i++){
            temp=fun(temp,s[i]);
        }
        return temp;
        
    }
};