class Solution {
public:
    int parent[100001];
     int cnt[100001];
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void connect(int a,int b){
        int x=find(a); int y=find(b);
        if(x==y) return ;
      cnt[y]+=cnt[x];
        //cnt[find(y)]+=cnt[find(x)];
             parent[x]=y;
        cnt[x]=0;
    }
    vector<int>fun(int n){
        vector<int>ans;
        if(n%2==0){
            while(n%2==0)n/=2;
            ans.push_back(2);
        }
        for(int i=3;i<=sqrt(n);i=i+2){
            if(n%i==0){
                ans.push_back(i);
               while(n%i==0) n/=i;
            }
        }
        if(n>2) ans.push_back(n);
        return ans;
    }
    int largestComponentSize(vector<int>& nums) {
        for(int i=0;i<100001;i++){parent[i]=i;cnt[i]=0;}
        for(auto a:nums){
            vector<int>temp=fun(a);
            for(auto t:temp){ 
              //  if(a==30)cout<<t<<endl;
                connect(a,t);
            }
            cnt[find(a)]++;
        }
        int mx=0;
        for(auto a:nums){
            int x=find(a);
           // cout<<x<<endl;
            mx=max(cnt[x],mx);
        }
        return mx;
    }
};