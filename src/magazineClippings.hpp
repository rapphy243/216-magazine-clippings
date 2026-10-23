#include <cctype>
#include <string>
#include <vector>
#include "hashMap.hpp"

bool canCreateNote(std::string note, std::vector<std::string> articles) {
    HashMap<char, int> charCount;
    for (int i = 0; i < articles.size(); i++) {
        for (char c : articles[i]) {
            if (std::isspace(c)) {
                continue; // Ignore spaces
            }
            if (std::isupper(c)) {
                c = std::tolower(c); // Convert to lowercase
            }
            charCount.get(c)++;
        }
    }
    for (char c : note) {
        if (std::isspace(c)) {
           continue; // Ignore spaces
        }
        if (std::isupper(c)) {
           c = std::tolower(c); // Convert to lowercase
        }
        charCount.get(c)--;
        if (charCount.get(c) < 0) {
            
            return false;
        }
    }
    return true;
}

bool canCreateNote(std::string note, std::string article) {
    std::vector<std::string> vec = { article };
    return canCreateNote(note, vec);
}
