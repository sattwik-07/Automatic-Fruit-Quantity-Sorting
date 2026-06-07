# Automatic Fruit Quantity Sorting

A C-based program that sorts fruits by quantity using the **Merge Sort** algorithm. Built as a practical demonstration of Design and Analysis of Algorithms (DAA) concepts.

---

## What It Does

- Accepts fruit names and their corresponding quantities as input
- Sorts them in **ascending order of quantity** using Merge Sort
- Outputs the sorted list in a clean, readable format

---

## Algorithm

**Merge Sort** — Divide and Conquer

| Property | Value |
|---|---|
| Time Complexity | O(n log n) — all cases |
| Space Complexity | O(n) auxiliary |
| Stable | Yes |

Merge Sort was chosen over simpler alternatives (Bubble, Selection) because it guarantees O(n log n) even in the worst case, making it suitable for larger datasets.

---

## Getting Started

### Prerequisites

- GCC or any C compiler

### Compile & Run

```bash
gcc fruit_sorting.c -o fruit_sorting
./fruit_sorting
```

### Example

```
Enter number of fruits: 4
Enter fruit name and quantity:
Mango 50
Apple 20
Banana 80
Orange 10

Sorted by quantity (ascending):
Orange   - 10
Apple    - 20
Mango    - 50
Banana   - 80
```

---

## Project Structure

```
Automatic-Fruit-Quantity-Sorting/
├── fruit_sorting.c      # Main program with Merge Sort implementation
└── README.md
```

---

## Concepts Demonstrated

- Merge Sort implementation in C
- Sorting structs by a numeric field
- Divide and conquer paradigm
- DAA course application

---

## License

This project is open source and available under the [MIT License](LICENSE).
