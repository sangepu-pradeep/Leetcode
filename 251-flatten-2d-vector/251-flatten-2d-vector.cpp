class Vector2D {
public:
    int x; int y;
    vector<vector<int>>v;
    Vector2D(vector<vector<int>>& vec) {
       x=0; y=0; v=vec;
    }
    
    int next() {
       
       // if(x>=v.size()||y>=v[x].size()) return -1;
        while(x<v.size()&&v[x].size()==0){
            x++;y=0;
        }
        int ans=v[x][y];
  
        if((y+1)<v[x].size())y++;
        else {x++;y=0;}
        return ans;
    }
    
    bool hasNext() {
   // return 1;
     while(x<v.size()&&v[x].size()==0){
            x++;y=0;
        }
     if(x>=v.size()||v[x].size()<=y) return 0;
      // if(v[x].size()>y+1||x+1<v.size()) return 1;
        return 1;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */