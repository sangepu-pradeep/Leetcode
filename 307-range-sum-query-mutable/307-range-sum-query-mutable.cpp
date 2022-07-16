class STree{
    public:
    vector<int>seg;
    STree(int n){
        seg.resize(4*n,0);
    }
    void build(int ind, int low, int high, vector<int>&nums){
        if(low==high){
            seg[ind]=nums[low]; return ;
        }
        int mid=(low+high)/2;
        build(2*ind+1,low,mid,nums);
        build(2*ind+2,mid+1,high,nums);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    void update(int ind, int low, int high, int i, int val){
        
        if(low==high){
           seg[ind]=val; return ;
        }
        int mid=(low+high)/2;
        if(i>mid) update(2*ind+2,mid+1,high,i,val);
        else update(2*ind+1,low,mid,i,val);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    int query(int ind, int low,int high, int l, int h){
       if (h < low || l > high){
            return 0;
        }
  
        if(low>=l&&h>=high){
            return seg[ind];
        }
    
        int mid=(low+high)/2;
        int left=query(2*ind+1, low, mid, l,h);
        int right=query(2*ind+2, mid+1,high,l,h);
        return right+left;
    }
    
};
class NumArray {
public:
   STree*a;int n;
    NumArray(vector<int>& nums) {
       n=nums.size();
       a=new STree(n);
       a->build(0,0,n-1,nums);
       // cout<<a->seg[0]<<" "<<a->seg[1]<<" "<<a->seg[2];
        
    }
    
    void update(int index, int val) {
        a->update(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return a->query(0,0,n-1,left,right);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */