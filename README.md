# 🎓 University C++ Fundamentals

> A comprehensive collection of C++ coursework completed during my university studies. This repository demonstrates a progression from fundamental algorithmic problem-solving to advanced Object-Oriented Programming (OOP), manual memory management, and custom data structures.

---

## 🛠️ Tech Stack & Concepts
- **Language:** C++ (Standard Library)
- **Core Concepts:** Algorithms, OOP, Polymorphism, Templates, Move Semantics, Dynamic Memory Allocation, Graph Theory.

---

## 📚 Coursework Breakdown

### `01_basic_algorithms.cpp` (Control Structures & Logic)
Demonstrates core programming logic without standard library shortcuts.
- Number system conversions (Base 10 to Base 2-9).
- Prime number identification and mathematical summations.
- Array/sequence analysis (growing/falling sequences).

### `02_oop_and_operators.cpp` (Classes & Encapsulation)
Focuses on encapsulation and operator overloading.
- **`RestaurantMenu`:** Manages ingredients, calculates combined prices, and handles allergen filtering.
- **`Student`:** Implements custom comparison operators (`>`, `<`, `>=`, `<=`) based on dynamically allocated and averaged marks.

### `03_templates_inheritance.cpp` (Generic Programming)
Explores generic programming and class hierarchies.
- **`MyVector<T>`:** A custom template-based dynamic array implementing `push_back` and automatic capacity resizing to prevent memory leaks.
- **Inheritance Chain:** `Human` ➔ `Student` ➔ `Bachelor` ➔ `Master`, demonstrating protected members, constructor chaining, and method overriding.

### `04_graph_data_structure.cpp` (Graph Theory)
Implements an undirected graph data structure from scratch.
- Converts an adjacency matrix into an edge list.
- Supports adding, removing, and retrieving edges dynamically.
- Includes a CLI-based interactive menu for real-time graph manipulation.

### `05_custom_linked_list/` (Dynamic Memory & Move Semantics)
A multi-file project implementing a custom Linked List for student group management.
- Custom `Node` structures to manage dynamic memory.
- Implementation of the **Rule of Five** (Destructors, Move Constructors, Move Assignment Operators) to optimize performance.
- Overloaded operators (`+`, `=`, `<<`) for intuitive syntax when adding students and formatting terminal output.