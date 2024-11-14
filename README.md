# Inventory Management System for Weapons

This C++ program is an inventory management system that allows users to store, search, and display information about "weapons" in an arsenal. The user can input new weapons with specific attributes, search through the inventory based on various criteria, and view the details of selected items.

## Features

- **Add New Weapons**: Input weapon details, including name, type, power level, durability, and level.
- **Search Inventory**: Search for weapons based on name, type, power level, durability, or level.
- **Display Weapon Details**: View details of a specific weapon in the inventory.

## Code Overview

The program uses a struct (`weapon`) to store weapon attributes. These attributes include:
- `name`: Name of the weapon
- `type`: Type of weapon (e.g., sword, gun)
- `power_level`: Power level of the weapon
- `durability`: Durability percentage
- `level`: Level requirement or ranking

A vector of `weapon` structs (`arsenal`) acts as the inventory. The program provides a menu to add new weapons, search the inventory, and display weapon information.

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Struct definition
typedef struct weapon{
    string name;
    string type;
    int power_level;
    int durability;
    int level;
} W;

// Function prototypes
void inputFunction(vector<W> &object, int n);
void printinventory(vector<W> &object, int n);
void searhFunction(vector<W> &object, string checker);

// Global variable for inventory index
int n = 0;

int main()
{
    vector <W> arsenal(1);
    string operationChecker = "";

    do {
        cout << "----------------Menu----------------------" <<endl;
        cout << "To input another weapon, type -- input" <<endl;
        cout << "To search existing weapon, type -- search" <<endl;
        cout << "To stop, type -- stop" <<endl;
        cout << "------------------------------------------" <<endl;
        
        cout << "What do you wish to do? --  ";
        cin >> operationChecker;

        for(int i=0; i<operationChecker.length(); i++)
            operationChecker[i] = tolower(operationChecker[i]);

        if(operationChecker == "input") {
            inputFunction(arsenal, n);
            arsenal.emplace_back();
            n++;
        }

        searhFunction(arsenal, operationChecker);

        if(operationChecker == "stop")
            break;

    } while(true);

    return 0;
}
```

## Functions

1. **`inputFunction`**: Adds a new weapon to the inventory. The function prompts the user for the weapon’s name, type, power level, durability, and level. Input validation ensures numeric fields are entered correctly.

2. **`printinventory`**: Displays the details of a specific weapon in the inventory.

3. **`searhFunction`**: Allows the user to search for weapons based on name, type, power level, durability, or level. Search results display matching weapons, or a "no result" message if no matches are found.

## Usage

1. **Compile the Program**:
   ```bash
   g++ -o inventory_management inventory_management.cpp
   ```

2. **Run the Program**:
   ```bash
   ./inventory_management
   ```

3. **Program Menu**:
   - Enter `input` to add a new weapon.
   - Enter `search` to search for a weapon based on different criteria.
   - Enter `stop` to exit the program.

4. **Search Categories**:
   - Search by `name` or `type` (string matches).
   - Search by `power level` or `durability` (input a range).
   - Search by `level` (input a specific level).

## Example

**Adding a Weapon**:
```plaintext
What do you wish to do? -- input
name -- Excalibur
type -- Sword
power level -- 100
durability -- 85
level -- 5
```

**Searching for a Weapon**:
```plaintext
What do you wish to do? -- search
pick a category to search by --- name, type, power level, durability, level:
name
what name: excalibur
```

## Notes

- **Case Sensitivity**: The program converts all inputs to lowercase for case-insensitive searches.
- **Error Handling**: Ensures numeric fields are validated for power level, durability, and level inputs.
- **Dynamic Inventory**: The program expands the inventory as new weapons are added.