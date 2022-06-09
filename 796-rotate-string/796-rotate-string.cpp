class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0;i<s.size();i++){
            if(s==goal) return 1;
            char temp=s.back();
            s.pop_back();
            s=temp+s;
        }
        return 0;
    }
};