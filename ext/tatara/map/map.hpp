#ifndef MAP_H_
#define MAP_H_

#include <unordered_map>

template <class K, class V>
class Map {
        std::unordered_map<K, V> container;
    public:
        constexpr Map();
        ~Map();
};

template <class K, class V>
constexpr Map<K, V>::Map() {}

template <class K, class V>
Map<K, V>::~Map() {}

#endif