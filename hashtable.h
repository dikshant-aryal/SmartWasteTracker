#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

struct Entry {
    std::string key;
    std::string value;
    bool isDeleted;

    Entry() : key(""), value(""), isDeleted(false) {}
    Entry(std::string k, std::string v) : key(k), value(v), isDeleted(false) {}
};

class HashTable {
private:
    Entry* table;
    int capacity;
    int size;
    int hash1(const std::string& key);
    int hash2(const std::string& key);
    int findSlot(const std::string& key, bool forInsert);
    void saveToFile();
    void loadFromFile();

public:
    HashTable(int cap = 101);
    ~HashTable();
    bool insert(const std::string& key, const std::string& value);
    std::string search(const std::string& key);
    bool update(const std::string& key, const std::string& newValue);
    bool remove(const std::string& key);
    void display();
};

#endif
