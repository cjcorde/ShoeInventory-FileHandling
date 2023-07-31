# C Language Shoe Inventory 

This repository contains a simple command-line based Shoe Inventory program implemented in the C programming language. The program allows users to manage shoe inventory records, including creating new shoe records, reading existing shoe records, updating shoe information, and deleting shoe records.

## Features

- **Create Shoe Inventory**: Users can add new shoe records to the inventory by providing stock numbers, style numbers, sizes, and prices.

- **Display Shoe Inventory**: Users can view all shoe records or search for specific shoes based on stock numbers, style numbers, or sizes.

- **Update Shoe Inventory**: Users can modify existing shoe records, changing the price or updating the stock on hand for specific sizes.

- **Delete Shoe Inventory**: Users can remove individual shoe records or clear the entire shoe inventory.

## How to Use

1. Clone the repository to your local machine.

2. Compile the C source code using a C compiler. For example:

   ```bash
   gcc -o ashoe_inventory ashoe_inventory.c
   ```

3. Run the executable:

   ```bash
   ./ashoe_inventory
   ```

4. The program will display a menu with options to perform various operations on the shoe inventory.

## Note

- Shoe inventory data is stored in the `inventory.txt` file, with each shoe record formatted as follows:
  ```
  STOCK NUMBER: XXX | STOCK STYLE: XX | SIZE: X X X X X X X X X X X X | PRICE: XXX.XX
  ```

- The program uses file handling to read and write shoe inventory records, allowing for persistence across different program executions.

- The program provides validation for stock numbers, style numbers, and sizes to avoid duplicate or invalid entries.

- This is a simplified implementation and may not cover all edge cases or error handling scenarios.

## Contributions

Contributions to the repository are welcome. If you find any issues or have ideas for improvements, feel free to create pull requests or raise issues.

**Disclaimer**: This Shoe Inventory program is intended for educational purposes only and may not be suitable for real-world commercial use. It lacks sophisticated security features and should not be used for critical business operations.

---
