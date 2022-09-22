class Solution {
public:
    string reverseWords(string s) {
        string temp; s.push_back(' ');string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                reverse(temp.begin(),temp.end());
                ans+=temp+" ";
                temp="";
            }else temp.push_back(s[i]);
        }
        ans.pop_back();
        return ans;
           
    }
};