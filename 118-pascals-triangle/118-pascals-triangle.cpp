class Solution {
public:

    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        vector<int>temp={1};
        while(n--){
            vector<int>curr;
            curr.push_back(1);
           for(int i=0;i<temp.size()-1;i++){
              curr.push_back(temp[i]+temp[i+1]); 
           }
            curr.push_back(1);    ans.push_back(temp);
            temp=curr;
        
        }
        return ans;
    }
};