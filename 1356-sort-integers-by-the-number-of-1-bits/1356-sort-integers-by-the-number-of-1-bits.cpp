class Solution {
public:
    vector<int> sortByBits(vector<int> arr) {
        auto comp=[](const auto &a,const auto &b){
            int p=__builtin_popcount(a); 
            int q=__builtin_popcount(b);
            return p==q?a<b:p<q;
        };
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};