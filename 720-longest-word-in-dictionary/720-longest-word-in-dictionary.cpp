class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_map<string,int>mp;
        for(auto a:words){
          mp[a]=1;  
        }
        string ans;
        for(auto a:words){
            string temp;bool b=0;
            for(auto t:a){
                temp.push_back(t);
                if(mp.find(temp)==mp.end()) {b=1;break;}
            }
            if(b==0){
              if(ans.size()<temp.size()) ans=temp;
                else if(ans.size()==temp.size()) ans=ans<temp?ans:temp;
            }
        }
        return ans;
    }
};