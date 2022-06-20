
class WordFilter {
public:
    struct TrieNode{
      int b;
        TrieNode*a[27];
        TrieNode(){
            for(int i=0;i<=26;i++) a[i]=NULL;
            b=-1;
        }
    };
    TrieNode*root;
    void insert(string s, int t){
        TrieNode*temp=root;
         // cout<<s<<" "<<t<<endl;
         for(auto a:s){
             int ind;
             if(a=='#')ind=26;
            else  ind=a-'a';
             if(temp->a[ind]==NULL) temp->a[ind]=new TrieNode();
            
             temp=temp->a[ind]; temp->b=t;
         }
    }
    int find(string &s){
        TrieNode*temp=root; int ans=-1;
        for(auto t:s){
              int ind;
            if(t=='#') ind=26;
            else ind=t-'a';
         //  cout<<temp->a[ind]<<endl;
        
            if(temp->a[ind]==NULL) return -1;
            temp=temp->a[ind];ans=temp->b;
        }
        return ans;
    }
    
    WordFilter(vector<string> words) {
     root=new TrieNode(); 
        //aa->words[i];
       // string u="a#e";
       // insert(u,0);
          //  TrieNode*temp=root;
        // temp->a[0]=new TrieNode(); temp=temp->a[0];
        // temp->b=0;
        for(int i=0;i<words.size();i++){
             string temp; string h=words[i];
            reverse(h.begin(),h.end());
            for(auto k:words[i]){
                temp.push_back(k);
                string hh=temp+"#"+h;
              //  cout<<hh<<endl;
                insert(hh,i);
            }
           
        }
          
//         string hh="aa";
        
//         insert(hh,0);
    }
    
    int f(string prefix, string suffix) {

        reverse(suffix.begin(),suffix.end());
        string t=prefix+"#"+suffix;
    
        //  string u="a#elppa"; insert(u,0);
        return find(t);
        
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */