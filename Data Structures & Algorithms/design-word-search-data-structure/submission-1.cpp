class WordDictionary {
    struct TrieNode {
        TrieNode* children[26];
        bool isLeaf = false;
        TrieNode() {
            for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
        }
        bool hasAnyChildren() {
	  for (int i = 0; i < 26; ++i) {
	    if (children[i]) return true;
	  }
	  return false;
        }
    };
    TrieNode *root = nullptr;

public:
    WordDictionary() {
        root = new TrieNode();        
    }
    
    void addWord(string word) {
        auto p = root;
        for (auto c: word) {
	        if (p->children[c-'a'] == nullptr) {
	            p->children[c-'a'] = new TrieNode();
	        }
	        p = p->children[c-'a'];
        }
        if (!p->isLeaf) p->isLeaf = true;
    }

    bool searchDfs(TrieNode *node, string word, int idx) {
        if (!node) return false;
        if (idx == word.size()) return node->isLeaf;
        char c = word[idx];
        if (c == '.') {
            for (int k = 0; k < 26; ++k) {
                if (node->children[k] && searchDfs(node->children[k], word, idx+1))
                    return true;
            }
            return false;
        } else if (node->children[c-'a']) {
            return searchDfs(node->children[c-'a'], word, idx+1);
        }
        return false;
    }
  
    bool search(string word) {
        return searchDfs(root, word, 0);
    }
};
