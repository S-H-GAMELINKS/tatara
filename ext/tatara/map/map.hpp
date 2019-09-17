#ifndef MAP_H_
#define MAP_H_

#include <unordered_map>

template <class K, class V>
class Map {
        std::unordered_map<K, V> container;
    public:
        constexpr Map();
        ~Map();
        constexpr V bracket(const K key);
        constexpr V bracket_equal(const K key, const V value);
};

template <class K, class V>
constexpr Map<K, V>::Map() {}

template <class K, class V>
Map<K, V>::~Map() {}

template <class K, class V>
constexpr V Map<K, V>::bracket(const K key) {
    return this->container[key];
}

template <class K, class V>
constexpr V Map<K, V>::bracket_equal(const K key, const V value) {
    return this->container[key] = value;
}

#endif