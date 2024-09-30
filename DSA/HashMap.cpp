#include "HashMap.h"

HashMap::HashMap() {
    table.resize(SIZE);
}

int HashMap::hashFunction(const std::string& key) const {
    std::hash<std::string> hashFunc;
    return hashFunc(key) % SIZE;
}

void HashMap::insert(const std::string& key, const std::string& value) {
    int index = hashFunction(key);
    for (auto& pair : table[index]) {
        if (pair.first == key) {
            pair.second = value; // Update value if key already exists
            return;
        }
    }
    table[index].emplace_back(key, value); // Insert new key-value pair
}

std::string HashMap::get(const std::string& key) const {
    int index = hashFunction(key);
    for (const auto& pair : table[index]) {
        if (pair.first == key) {
            return pair.second; // Return the value for the key
        }
    }
    return ""; // Return empty string if key not found
}

