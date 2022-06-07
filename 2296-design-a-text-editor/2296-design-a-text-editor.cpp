class TextEditor {
public:
    struct Node{
        char c;
        Node*left; Node*right;
        Node(char p){
            c=p;left=NULL;right=NULL;
        }
    };
    Node*curr; Node*st;
    TextEditor() {
      curr=new Node('?');
    st=curr;
    }
    
    void addText(string text) {
        Node*temp=curr;
        Node*f=curr->right;
        for(int i=0;i<text.size();i++){      
            Node*p=new Node(text[i]);
            temp->right=p;
            Node*t=temp;
            temp=temp->right;
            temp->left=t;
        }
        curr=temp;
        curr->right=f;
       if(f) f->left=curr;
    }
    
    int deleteText(int k) {
        int cnt=0;string temp;
    
         Node*f=curr->right;
        while(curr!=st&&k--){
            temp.push_back(curr->c);
        curr=curr->left;cnt++;
        }
     
        curr->right=f;
       if(f) f->left=curr;
  //cout<<temp;
        return cnt;
    }
    
    string cursorLeft(int k) {
        while(curr!=st&&k--){
           curr=curr->left;
        }
     Node*temp=curr; 
        int g=10;string ans;
        while(g--&&temp!=st){
            ans.push_back(temp->c); temp=temp->left;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    string cursorRight(int k) {
        while(curr->right!=NULL&&k--){
            curr=curr->right;
        }
        Node*temp=curr;
        int g=10;string ans;
        while(g--&&temp!=st){
           ans.push_back(temp->c); temp=temp->left;
        }
          reverse(ans.begin(),ans.end());
        return ans;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */