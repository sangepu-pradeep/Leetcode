class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
       vector<int> a=score;
        auto comp=[](const auto a,const auto &b){
           return a>b; 
        };
        sort(a.begin(),a.end(),comp);
         unordered_map<int,int>mp;
        for(int i=0;i<a.size();i++){
            mp[a[i]]=i+1;
        }
        vector<string>ans;
        for(int i=0;i<score.size();i++){
            int t=mp[score[i]];
            if(t==1)ans.push_back("Gold Medal");
            else if(t==2) ans.push_back("Silver Medal");
            else if(t==3)ans.push_back("Bronze Medal");
            else {
                string p=to_string(t);
                ans.push_back(p);
            }
        }
        return ans;
    }
};