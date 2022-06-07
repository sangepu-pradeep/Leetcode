class Solution {
public:
    string fun(int n){
        if(n==1) return "0";
        string temp=fun(n-1);
        string inv;
        for(int i=0;i<temp.size();i++){
        if(temp[i]=='1')inv.push_back('0');
            else inv.push_back('1');
        }
        reverse(inv.begin(),inv.end());
        return (temp+"1"+inv);
    }
    char findKthBit(int n, int k) {
        string p=fun(n);
        return p[k-1];
    }
};