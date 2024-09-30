#include "Trie.h"

TrieNode::TrieNode() : isEndOfWord(false) {}

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const std::string& word) {
    TrieNode* current = root;
    for (char c : word) {
        if (current->children.find(c) == current->children.end()) {
            current->children[c] = new TrieNode();
        }
        current = current->children[c];
    }
    current->isEndOfWord = true;
}

void Trie::autoCompleteHelper(TrieNode* node, const std::string& prefix, std::vector<std::string>& results) const {
    if (node->isEndOfWord) {
        results.push_back(prefix);
    }
    for (const auto& pair : node->children) {
        autoCompleteHelper(pair.second, prefix + pair.first, results);
    }
}

std::vector<std::string> Trie::autoComplete(const std::string& prefix) const {
    std::vector<std::string> results;
    TrieNode* current = root;
    for (char c : prefix) {
        if (current->children.find(c) == current->children.end()) {
            return results; // Prefix not found
        }
        current = current->children[c];
    }
    autoCompleteHelper(current, prefix, results);
    return results;
}

