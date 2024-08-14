//
// Created by shaba on 14.08.2024.
//
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <iostream>
#include <thread>

template <typename Key, typename Value>
struct LinkedList{
    Key key;
    Value value;
    struct LinkedList* next;
    struct LinkedList* prev;
    LinkedList(Key key, Value val) : key(key), value(val), next(nullptr), prev(nullptr) {};
    LinkedList() : next(nullptr), prev(nullptr) {};
};

template <typename Key, typename Value>
class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity),
    size(0), nodesMap(), head(new LinkedList<Key, Value>()), tail(new LinkedList<Key, Value>()) {};
    ~LRUCache() {
        // Освобождение памяти
        while (head) {
            LinkedList<Key, Value>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    Value get(Key key);
    void put(Key key, Value val);
private:
    int capacity;
    int size;
    struct LinkedList<Key, Value>* head;
    struct LinkedList<Key, Value>* tail;
    std::unordered_map<Key, LinkedList<Key, Value>*> nodesMap;

    void promote(LinkedList<Key, Value>* node);
    void append(LinkedList<Key, Value>* node);
    void evict(LinkedList<Key, Value>* node);
};

template <typename Key, typename Value>
Value LRUCache<Key, Value>::get(Key key) {
        if (nodesMap.find(key) == nodesMap.end()) return Value();
        LinkedList<Key, Value>* node = nodesMap[key];
        promote(node);
        return node->value;
}

template <typename Key, typename Value>
void LRUCache<Key, Value>::put(Key key, Value val) {
    if (nodesMap.find(key) != nodesMap.end()) {
        LinkedList<Key, Value>* node = nodesMap[key];
        node->value = val;
        promote(node);
    } else {
        LinkedList<Key, Value>* node = new LinkedList(key, val);
        append(node);
    }
}

template <typename Key, typename Value>
void LRUCache<Key, Value>::promote(LinkedList<Key, Value>* node) {
    evict(node);
    append(node);
}

template <typename Key, typename Value>
void LRUCache<Key, Value>::append(LinkedList<Key, Value>* node) {
        nodesMap[node->key] = node;

        if (!head->next) {
            // First node to append.
            head->next = node;
            tail->prev = node;
            node->prev = head;
            node->next = tail;
        } else {
            // Append to an existing tail.
            LinkedList<Key, Value>* oldTail = tail->prev;
            oldTail->next = node;
            node->prev = oldTail;
            node->next = tail;
            tail->prev = node;
        }

        size += 1;

        if (size > capacity) {
            evict(head->next);
        }
}

template <typename Key, typename Value>
void LRUCache<Key, Value>::evict(LinkedList<Key, Value>* node) {
        nodesMap.erase(node->key);
        size -= 1;

        LinkedList<Key, Value>* prevNode = node->prev;
        LinkedList<Key, Value>* nextNode = node->next;

        // If one and only node.
        if (prevNode == head && nextNode == tail) {
            head->next = nullptr;
            tail->prev = nullptr;
            size = 0;
            return;
        }

        // If this is a Head node.
        if (prevNode == head) {
            nextNode->prev = head;
            head->next = nextNode;
            return;
        }

        // If this is a Tail node.
        if (nextNode == tail) {
            prevNode->next = tail;
            tail->prev = prevNode;
            return;
        }

        // If the node is in the middle.
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
}

int expensiveFunction(int x) {
    // Имитация дорогой функции
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Имитируем задержку
    return x * x; // Например, возврат квадрата числа
}

int main(){
    const int cacheSize = 3;
    LRUCache<int, int> cache(cacheSize);

//    auto memoizedFunction = [&](int x) {
//        int cachedValue = cache.get(x);
//        if (cachedValue != 0) {
//            return cachedValue;
//        } else {
//            int result = expensiveFunction(x);
//            cache.put(x, result);
//            return result;
//        }
//    };

    auto memoizedFunction = [&](int x) {
        auto start = std::chrono::high_resolution_clock::now();
        int cachedValue = cache.get(x);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> cacheDuration = end - start;

        if (cachedValue != 0) { // Предполагаем, что 0 - это значение по умолчанию, которое не должно присутствовать в кэше.
            std::cout << "Cache hit for " << x << ": " << cachedValue << " (Time: " << cacheDuration.count() << " ms)" << std::endl;
            return cachedValue;
        } else {
            start = std::chrono::high_resolution_clock::now();
            int result = expensiveFunction(x);
            end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> functionDuration = end - start;
            cache.put(x, result);
            std::cout << "Cache miss for " << x << ": " << result << " (Expensive function time: " << functionDuration.count() << " ms)" << std::endl;
            return result;
        }
    };

    std::cout << memoizedFunction(2) << std::endl; // Кеш будет заполнен
    std::cout << memoizedFunction(3) << std::endl; // Кеш будет заполнен
    std::cout << memoizedFunction(2) << std::endl; // Использует кеш
    std::cout << memoizedFunction(4) << std::endl; // Кеш будет заполнен
    std::cout << memoizedFunction(3) << std::endl; // Использует кеш
    std::cout << memoizedFunction(2) << std::endl; // Использует кеш
    std::cout << memoizedFunction(5) << std::endl; // Кеш вытеснит 4
    std::cout << memoizedFunction(2) << std::endl; // Использует кеш
    std::cout << memoizedFunction(4) << std::endl;



}