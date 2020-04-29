// Source : https://oj.leetcode.com/problems/<insert problem>/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* 
* Implement a trie with insert, search, and startsWith methods.
* 
* Example:
* 
* Trie trie = new Trie();
* 
* trie.insert("apple");
* trie.search("apple");   // returns true
* trie.search("app");     // returns false
* trie.startsWith("app"); // returns true
* trie.insert("app");   
* trie.search("app");     // returns true
* Note:
* 
* You may assume that all inputs are consist of lowercase letters a-z.
* All inputs are guaranteed to be non-empty strings.
*               
**********************************************************************************/

class Trie {
public:
    class Node {
    public:
        vector<Node*> children;
        bool is_leaf;
        Node() {
            is_leaf = false;
            children.resize(26, nullptr);
        }
    };
    Node* root = nullptr;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); ++i) {
            if (node->children[word[i] - 'a'] == nullptr) {
                node->children[word[i] - 'a'] = new Node();
            }
            node = node->children[word[i] - 'a'];
        }
        node->is_leaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); ++i) {
            if (node->children[word[i] - 'a'] == nullptr) return false;
            node = node->children[word[i] - 'a'];
        }
        return node->is_leaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); ++i) {
            if (node->children[word[i] - 'a'] == nullptr) return false;
            node = node->children[word[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */