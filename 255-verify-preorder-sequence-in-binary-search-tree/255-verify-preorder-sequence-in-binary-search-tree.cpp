class Solution {
public:
    // bool fun(int st, int ed,vector<int>&nums){
    //     if(st>=ed)return 1;
    //  int i=st+1; int ans=1;
    //     while(i<=ed&&nums[i]<nums[st]){
    //         i++;
    //     }
    //     ans=(ans&(fun(st+1,i-1,nums)));
    //     int p=i;
    //     while(i<=ed){
    //         if(nums[i]<nums[st]) return 0;
    //         i++;
    //     }
    //     ans=ans&(fun(p,ed,nums));
    //     return ans;
    // }
    bool fun(int st, int ed, vector<int>&pre,vector<int>&in, int &ind){
        if(st>ed) return 1;
        ind++;
      //  static int ind=0;
         int p=lower_bound(in.begin()+st,in.begin()+(ed+1),pre[ind])-in.begin();
        if(p>ed||in[p]!=pre[ind]) return 0;
        int ans=1;
        ans=ans&(fun(st,p-1,pre,in,ind));

        ans=ans&(fun(p+1,ed,pre,in,ind));
    
        return ans;
    }
    bool verifyPreorder(vector<int>& pre) {
        auto in=pre;
        sort(in.begin(),in.end()); int ind=-1;
        return fun(0,pre.size()-1,pre,in,ind);
    }
};