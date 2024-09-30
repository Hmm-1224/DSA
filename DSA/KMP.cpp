#include "KMP.h"

std::vector<int> KMP::computeLPSArray(const std::string& pattern) {
    int length = 0;
    int i = 1;
    std::vector<int> lps(pattern.length(), 0);

    while (i < pattern.length()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

std::vector<int> KMP::search(const std::string& text, const std::string& pattern) {
    std::vector<int> lps = computeLPSArray(pattern);
    std::vector<int> indices;

    int i = 0; // Index for text
    int j = 0; // Index for pattern
    while (i < text.length()) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == pattern.length()) {
            indices.push_back(i - j);
            j = lps[j - 1];
        } else if (i < text.length() && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return indices;
}

