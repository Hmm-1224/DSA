#ifndef KMP_H
#define KMP_H

#include <iostream>
#include <vector>
#include <string>

class KMP {
public:
    static std::vector<int> search(const std::string& text, const std::string& pattern);
private:
    static std::vector<int> computeLPSArray(const std::string& pattern);
};

#endif // KMP_H

