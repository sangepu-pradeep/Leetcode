class MyCalendar {
public:
    set<pair<int,int>>st;
    MyCalendar() {
       st={}; 
    }
    
    bool book(int start, int end) {
      auto a=st.lower_bound({start,end});
        if(a!=st.end()&&a->first<=end-1) return 0;
        if(a!=st.begin()&&(--a)->second>=start) return 0;
        st.insert({start,end-1});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */