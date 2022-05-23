class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>>ans;
        for(int i=0;i<s.size();i++){
            char c=s[i]; int st=i;
            while(i+1<s.size()&&s[i+1]==c){i++;}
            if(i-st+1>=3) ans.push_back({st,i});
        }
        return ans;
    }
};