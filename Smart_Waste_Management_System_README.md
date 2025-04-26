
# Smart Waste Management System

## Overview
This project implements a waste management system using a Hash Tableas the primary data structure to track waste bins, their fill levels, and perform CRUD operations (Create, Read, Update, Delete). It simulates an overflow alert system that alerts when a bin reaches its maximum capacity.

## Features
- **CRUD Operations**: 
    - **Insert**: Adds new bins with waste levels.
    - **Search**: Retrieves the waste level for a given bin.
    - **Update**: Modifies the waste level of an existing bin.
    - **Delete**: Removes a bin.
    - **Display**: Shows all bins and their waste levels.
- **Overflow Simulation**: Simulates an alert for bins that are "full."
- **Persistence**: Bin data is saved to and loaded from a file (`waste_bins.txt`).

## File Structure
- `main.cpp`: Contains the main program logic, including the menu-driven interface.
- `HashTable.cpp`: Contains the implementation of the `HashTable` class and the associated methods (`insert`, `search`, `update`, `remove`, etc.).
- `hashtable.h`: Declares the `HashTable` class and its methods.
- `waste_bins.txt`: File that stores the bin data persistently.

## Instructions

### Compilation
To compile the project, run the following command in your terminal:

```bash
g++ -o waste_management main.cpp HashTable.cpp
```

### Running the Program
Once compiled, run the program by executing:

```bash
./waste_management
```

This displays a menu where you can choose from various choices to interact with the waste management system.

### Menu Options:
1. **Insert Bin**: Allows you to insert a new bin by providing a **bin ID** and **waste level**.
2. **Search Bin**: Allows you to search for a bin by its **bin ID** and see its **waste level**.
3. **Update Bin**: Allows you to update the **waste level** of an existing bin.
4. **Delete Bin**: Allows you to delete a bin from the system by providing its **bin ID**.
5. **Display Bins**: Displays all bins in the system with their **bin ID** and **waste level**.
6. **Simulate Overflow Alert**: Simulates an overflow alert for a given bin if it is **full**.
7. **Exit**: Exits the program.

### Example Interaction:
```
1. Insert Bin
2. Search Bin
3. Update Bin
4. Delete Bin
5. Display Bins
6. Simulate Overflow Alert
7. Exit
Choice: 1

Enter bin ID (numeric value): 1
Enter waste level (e.g., 'half full', 'full'): half full
Bin inserted successfully.
```

### How Data is Stored:
- The **bin ID** is stored as the **key**, and the **waste level** is stored as the **value** in the hash table.
- Data is saved to a file (`waste_bins.txt`) after any modification, so the system can load and retain bin data even after restarting the program.

## Testing
You can test the following operations:
- **Insert** bins with different waste levels.
- **Search** for bins by ID and check their waste levels.
- **Update** the waste level of an existing bin.
- **Delete** bins from the system.
- **Display** all bins.
- **Simulate overflow alerts** for full bins.

## Conclusion
This project demonstrates the use of a **hash table** for managing waste bins in an efficient way. The system allows for CRUD operations, simulates overflow alerts, and saves data persistently. The waste management system is designed to be user-friendly and efficient for handling urban waste management tasks.
