class PrefixTree {
    struct TrieNode {
        TrieNode* children[26];
        bool isLeaf = false;
        TrieNode() {
            for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
        }
    };
    TrieNode *root = nullptr;
public:

    PrefixTree() {
        root = new TrieNode();        
    }
    
    void insert(string word) {
        auto p = root;
        for (auto c: word) {
            if (p->children[c-'a'] == nullptr) {
                p->children[c-'a'] = new TrieNode();
            }
            p = p->children[c-'a'];
        }
        if (!p->isLeaf) p->isLeaf = true;
    }
    
    bool search(string word) {
        auto p = root;
        for (auto c: word) {
            if (p->children[c-'a']) {
                p = p->children[c-'a'];
            } else {
                return false;
            }
        }
        if (!p || p->isLeaf == false) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        auto p = root;
        for (auto c: prefix) {
            if (p->children[c-'a']) {
                p = p->children[c-'a'];
            } else {
                return false;
            }
        }
        return true;
    }
};
