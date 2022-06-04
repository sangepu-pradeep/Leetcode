class StockSpanner {
public:
    stack<int>st; 
    vector<int>num;
    StockSpanner() {
        num={}; 
        st={};
    }
    
    int next(int price) {
      
        int p=num.size();
        // if(st.size()==0) {         
        //     st.push(p); return (p+1);}
        int l=0;
        while(st.size()&&price>=num[st.top()]){
            st.pop();
        }
       // st.push(p);
        if(st.size()==0) {  num.push_back(price);st.push(p);return p+1;}
    int ans =p-st.top(); st.push(p);
          num.push_back(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */