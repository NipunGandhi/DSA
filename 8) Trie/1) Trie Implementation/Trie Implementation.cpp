struct Node{
    Node *links[26];
    bool flag = false;

    bool hasConnection(char c){
        if(links[c-'a'] != NULL) return true;
        else return false;
    }

    void insertNode(char c){
        links[c-'a'] = new Node();
    }

    void wordEnd(){
        flag = true;
    }

    Node* next(char c){
        return links[c-'a'];
    }

    bool getFlag(){
        return flag;
    }
};

class Trie {
public:
    private:
	Node* root;
    
    public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(!temp->hasConnection(c)){
                temp->insertNode(c);
            }
            temp = temp->next(c);
        } 
        temp->wordEnd();
    }
    
    bool search(string word) {
        Node* temp = root;
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(!temp->hasConnection(c)){
                return false;
            }
            temp = temp->next(c);
        } 
        return temp->getFlag();
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(int i = 0; i < prefix.size(); i++){
            char c = prefix[i];
            if(!temp->hasConnection(c)){
                return false;
            }
            temp = temp->next(c);
        } 
        return true;
    }
};
