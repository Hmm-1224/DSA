#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <unordered_map>
#include <vector>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode();
};

class Trie {
private:
    TrieNode* root;

public:
    Trie();
    void insert(const std::string& word);
    std::vector<std::string> autoComplete(const std::string& prefix) const;

private:
    void autoCompleteHelper(TrieNode* node, const std::string& prefix, std::vector<std::string>& results) const;
};

#endif // TRIE_H

