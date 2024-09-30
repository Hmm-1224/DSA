#include <iostream>
#include <vector>
#include "HashMap.h"
#include "Trie.h"
#include "KMP.h"

int main() {
    // Example usage of HashMap
    HashMap trainRoutes;
    trainRoutes.insert("Train1", "RouteA");
    trainRoutes.insert("Train2", "RouteB");

    std::cout << "Train1 Route: " << trainRoutes.get("Train1") << std::endl;

    // Example usage of Trie
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apricot");

    std::vector<std::string> completions = trie.autoComplete("ap");
    std::cout << "Autocomplete suggestions for 'ap':" << std::endl;
    for (const auto& word : completions) {
        std::cout << word << std::endl;
    }

    // Example usage of KMP
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABCABAB";
    std::vector<int> indices = KMP::search(text, pattern);

    std::cout << "Pattern found at indices: ";
    for (int index : indices) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}

