#include "hashtable.h"
#include <iostream>
#include <string>

void printMenu() {
    std::cout << "\n1. Insert Bin\n2. Search Bin\n3. Update Bin\n4. Delete Bin\n5. Display Bins\n6. Simulate Overflow Alert\n7. Exit\n\nChoice: ";
}

int main() {
    HashTable ht; // Initialize the hash table
    int choice;
    std::string key, value;
    std::string alertMessage = "";
    std::string wasteLevel = "";

    while (true) {
        printMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        std::cin.ignore(10000, '\n');

        switch (choice) {
            case 1:  // Insert a bin
                std::cout << "Enter bin ID: ";
                std::getline(std::cin, key);
                std::cout << "Enter waste level ('half full', 'full'): ";
                std::getline(std::cin, value);
                if (ht.insert(key, value))
                    std::cout << "\nBin inserted successfully.\n";
                else
                    std::cout << "\nInsertion failed (table full or duplicate bin).\n";
                break;
            case 2:  // Search for a bin
                std::cout << "Enter bin ID to search: ";
                std::getline(std::cin, key);
                std::cout << "Bin Waste Level: " << ht.search(key) << "\n";
                break;
            case 3:  // Update bin
                std::cout << "Enter bin ID to update: ";
                std::getline(std::cin, key);
                std::cout << "Enter new waste level: ";
                std::getline(std::cin, value);
                if (ht.update(key, value))
                    std::cout << "\nBin updated successfully.\n";
                else
                    std::cout << "\nBin not found.\n";
                break;
            case 4:  // Delete a bin
                std::cout << "Enter bin ID to delete: ";
                std::getline(std::cin, key);
                if (ht.remove(key))
                    std::cout << "\nBin deleted successfully.\n";
                else
                    std::cout << "\nBin not found.\n";
                break;
            case 5:  // Display all bins
                ht.display();
                break;
            case 6:  // Simulate overflow alert for bins that are full
                std::cout << "Enter bin ID to check for overflow: ";
                std::getline(std::cin, key);

                wasteLevel = ht.search(key);  // Get the waste level for the bin

                if (wasteLevel == "full") {
                    std::cout << "\nAlert: Overflow detected! Bin ID: " << key << ", Waste Level: " << wasteLevel << "\n";
                } else if (wasteLevel == "Key not found!") {
                    std::cout << "\nBin not found.\n";
                } else {
                    std::cout << "Bin ID: " << key << " is not full. Current Waste Level: " << wasteLevel << "\n";
                }
                break;
            case 7:  // Exit the program
                std::cout << "\nExiting...\n";
                return 0;
            default:
                std::cout << "Invalid option. Choose 1-7.\n";
        }
    }
}