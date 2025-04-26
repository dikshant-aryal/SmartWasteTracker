#include "hashtable.h"
#include <iostream>
#include <fstream>
#include <sstream>

HashTable::HashTable(int cap) : capacity(cap), size(0) {
    table = new Entry[capacity];
    for (int i = 0; i < capacity; ++i) {
        table[i] = Entry();  // Initialize all entries
    }
    loadFromFile();  // Load existing data from the file
}

HashTable::~HashTable() {
    delete[] table;
}

int HashTable::hash1(const std::string& key) {
    int hash = 0;
    for (char ch : key)
        hash = (hash * 31 + ch) % capacity;
    return hash;
}

int HashTable::hash2(const std::string& key) {
    int hash = 0;
    for (char ch : key)
        hash = (hash * 17 + ch) % (capacity - 1);
    return 1 + hash;
}

int HashTable::findSlot(const std::string& key, bool forInsert) {
    int index = hash1(key);
    int step = hash2(key);
    int i = 0;

    while (i < capacity) {
        int probe = (index + i * i) % capacity;
        if (table[probe].key == "" || table[probe].isDeleted) {
            if (forInsert) return probe;
        } else if (table[probe].key == key && !table[probe].isDeleted) {
            return forInsert ? -2 : probe;
        }
        ++i;
    }
    return -1;
}

bool HashTable::insert(const std::string& key, const std::string& value) {
    int slot = findSlot(key, true);
    if (slot == -1) return false;
    if (slot == -2) return false; 
    table[slot] = Entry(key, value);
    size++;
    saveToFile();  // Save data after insertion
    return true;
}

std::string HashTable::search(const std::string& key) {
    int slot = findSlot(key, false);
    if (slot != -1)
        return table[slot].value;
    return "Key not found!";
}

bool HashTable::update(const std::string& key, const std::string& newValue) {
    int slot = findSlot(key, false);
    if (slot != -1) {
        table[slot].value = newValue;
        saveToFile();  // Save data after updating
        return true;
    }
    return false;
}

bool HashTable::remove(const std::string& key) {
    int slot = findSlot(key, false);
    if (slot != -1) {
        table[slot].isDeleted = true;
        size--;
        saveToFile();  // Save data after removal
        return true;
    }
    return false;
}

void HashTable::display() {
    std::cout << "\nHash Table Contents (size: " << size << "/" << capacity << "):\n";
    for (int i = 0; i < capacity; ++i) {
        if (!table[i].key.empty() && !table[i].isDeleted)
            std::cout << "[" << i << "] " << table[i].key << " : " << table[i].value << "\n";
    }
}

void HashTable::saveToFile() {
    std::ofstream outFile("waste_bins.txt");
    for (int i = 0; i < capacity; ++i) {
        if (!table[i].key.empty() && !table[i].isDeleted)
            outFile << table[i].key << " " << table[i].value << "\n";
    }
    outFile.close();
}

void HashTable::loadFromFile() {
    std::ifstream inFile("waste_bins.txt");
    std::string key, value;
    while (inFile >> key >> value) {
        insert(key, value);  // Insert each entry from file
    }
    inFile.close();
}
