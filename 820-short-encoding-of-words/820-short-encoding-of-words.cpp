class Solution {
public:
    struct TrieNode{
       TrieNode*a[26];
        TrieNode(){
            for(int i=0;i<26;i++) a[i]=NULL;
        }
    };
    TrieNode*root;
    void insert(string &a){
        TrieNode*temp=root;
        for(auto t:a){
            int ind=t-'a';
            if(temp->a[ind]==NULL) temp->a[ind]=new TrieNode();
            temp=temp->a[ind];
        }
    }
    bool find(string &s){
        TrieNode*temp=root;
        for(auto a:s){
            int ind=a-'a';
            if(temp->a[ind]==NULL) return 0;
            temp=temp->a[ind];
        }
        return 1;
    }
    int minimumLengthEncoding(vector<string>& words) {
        root=new TrieNode();
        auto comp=[](auto const&a,auto const&b){
            return a.size()>b.size();
        };
        int cnt=0;
    sort(words.begin(),words.end(),comp);
        for(auto a:words){
            reverse(a.begin(),a.end());
            if(find(a)==0){
                insert(a);cnt+=(a.size()+1);
            }
        }
        
    return cnt;
    }
};