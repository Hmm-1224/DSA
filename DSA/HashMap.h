#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <vector>
#include <list>
#include <utility> // For std::pair

class HashMap {
private:
    static const int SIZE = 100;
    std::vector<std::list<std::pair<std::string, std::string>>> table;

    int hashFunction(const std::string& key) const;

public:
    HashMap();
    void insert(const std::string& key, const std::string& value);
    std::string get(const std::string& key) const;
};

#endif // HASHMAP_H

