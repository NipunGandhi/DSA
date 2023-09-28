struct Node {
    Node* links[26];
    bool flag = false;

    bool isAvailable(char c) {
        return links[c - 'a'] != nullptr;
    }

    Node* next(char c) {
        return links[c - 'a'];
    }

    void create(char c) {
        links[c - 'a'] = new Node();
    }

    void end() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class WordDictionary {
private:
    Node* root;

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* temp = root;
        for (char c : word) {
            if (!temp->isAvailable(c)) {
                temp->create(c);
            }
            temp = temp->next(c);
        }
        temp->end();
    }

    bool search(string word, int i = 0, Node* temp = nullptr) {
        if (temp == nullptr) temp = root;

        for (i; i < word.size(); i++) {
            char c = word[i];
            if (c != '.') {
                if (!temp->isAvailable(c)) {
                    return false;
                }
                temp = temp->next(c);
            } else {
                for (int j = 0; j < 26; j++) {
                    Node* val = temp->next('a'+ j);
                    if (val == NULL) continue;
                    bool ans = search(word, i + 1, val);
                    if (ans) return ans;
                }
                return false;
            }
        }
        return temp->isEnd();
    }
};
