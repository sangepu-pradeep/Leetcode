struct trieNode{
    trieNode*children[26];
    bool end_word;
    trieNode(){
         for(int i=0;i<26;i++) children[i]=NULL;
        end_word=0;
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
  trieNode*root;
    Trie() {
        root=new trieNode();
       
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        trieNode*temp=root;
        for(char c:word){
            int index=c-'a';
            if(temp->children[index]==NULL)
                temp->children[index]=new trieNode();
            temp=temp->children[index];
        }
        temp->end_word=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trieNode*temp=root;
        for(char c:word){
            int index=c-'a';
            if(temp->children[index]==NULL) return 0;
            temp=temp->children[index];
        }
        if(temp->end_word==0) return 0;
        return 1;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
         trieNode*temp=root;
        for(char c:prefix){
            int index=c-'a';
            if(temp->children[index]==NULL) return 0;
            temp=temp->children[index];
        }
        if(temp==NULL) return 0;
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */