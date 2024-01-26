# Point of Sale System - Read Me

## Overview

This C++ Point of Sale (POS) System is designed to handle transactions for various tools, providing features such as SKU validation, item name length check, and pricing verification. The system allows users to input information related to tools, and it generates a summary of the items, their prices, and total costs.

## Instructions

To run the program, execute the command:
```bash
./ms
```

Follow the on-screen prompts to enter tool information and observe the system's responses.

## Features

- **Input Validation:** The system validates SKU length, item name length, price, quantity, and tax input to ensure data integrity.

- **Tool Information Display:** Displays a formatted list of tool information, including SKU, name, price, tax status, quantity, and total cost.

- **Dictionary Output:** Outputs the first item in the dictionary, showing SKU, name, price, price with tax, and stock quantity.

- **Cost Summary:** Presents a summary of the total cost of all items, including a breakdown of quantity changes for each tool.

- **Heap Summary:** Provides information on heap usage, ensuring there are no memory leaks.

## Usage Examples

1. Invalid SKU Length: Records SKU too long.
2. Invalid Item Name Length: Records item name too long.
3. Invalid Price: Records invalid price value.
4. Invalid Quantity: Records invalid quantity value.
5. Successful Transactions: Displays tool information and total cost.

## Output Files

The program generates a file named `<thefile>` containing transaction records in CSV format.

## Heap Summary

The system utilizes dynamic memory allocation and ensures proper deallocation without memory leaks.

## Notes

- This project uses Valgrind for memory error detection. No errors were reported in the provided output.