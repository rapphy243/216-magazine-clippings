#include <list>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

template <typename K, typename V>
class HashMap {
private:
    std::vector<std::list<std::pair<K, V>>> buckets{256};

    int hash(K key)  {
        int hash = 0;

        if constexpr (std::is_same_v<K, std::string>) { // Check if K is a string
            for (char character : key) {
                hash = hash * 31 + character;
            }
        } else {
            unsigned char *bytes = (unsigned char*) &key; // I think this is fine?
            for (int i = 0; i < sizeof(K); ++i){
                hash = (hash << 8) + bytes[i];
            }
        }

        return hash;
    }

    int getHashIndex(K key)  {
        return ((31 * hash(key) + 7) % 7919) % buckets.size();
    }

public:
    void put(const K& key, const V& value) {
        for (std::pair<K, V>& entry : buckets[getHashIndex(key)]) {
            if (entry.first == key) { // Key already exists, update value
                entry.second = value;
                return;
            }
        }

        buckets[getHashIndex(key)].push_back({key, value});
    }

    V& get(K key) {
        for (std::pair<K, V>& entry : buckets[getHashIndex(key)]) {
            if (entry.first == key) {
                return entry.second;
            }
        }
        // I dont feel like handling exceptions/changing previous code
        V temp = V(); 
        put(key, temp);
        return get(key);
    }

    bool contains(K key) {
        for (std::pair<K, V>& entry : buckets[getHashIndex(key)]) {
            if (entry.first == key) {
                return true;
            }
        }

        return false;
    }
};
