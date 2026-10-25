# Data Structures & Algorithms in Modern C++

**Rigorous implementations, algorithmic proofs, and hardware-conscious memory models.**

[![Language](https://img.shields.io/badge/Language-C%2B%2B17-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)](https://en.cppreference.com/w/cpp/17)
[![Coursework](https://img.shields.io/badge/Coursework-UET%20Taxila%20BSCS-8B1E1E?style=flat-square)](https://uettaxila.edu.pk/)
[![Complexity](https://img.shields.io/badge/Complexity-Rigorous%20%F0%9D%94%AA(n)-C9A84C?style=flat-square)](#algorithmic-complexity-reference)
[![Standard](https://img.shields.io/badge/Standard-Zero%20Dependency-10B981?style=flat-square)](#compilation--toolchain)

---

## Overview

This repository houses a comprehensive, zero-dependency codebase of **Data Structures and Algorithms** written in standard **C++17**. Developed alongside the Computer Science curriculum at **UET Taxila**, the implementations prioritize low-level mechanical sympathy: cache locality, pointer mechanics, manual heap allocations, and strict memory safety over high-level runtime abstractions.

Rather than treating data structures as academic pseudocode, each module investigates the physical constraints of execution:
- **Contiguous vs. Linked Layout:** Cache spatial locality of flat buffers vs. pointer dereferencing penalties.
- **Pointer Invariants:** Safe pointer arithmetic, double-pointer (`Node**`) and reference-to-pointer (`Node*&`) head modifications, and cyclic link prevention.
- **Memory Hygiene:** Dynamic `new[]`/`delete[]` lifecycle discipline, RAII encapsulation patterns, and heap fragmentation considerations.

---

## Algorithmic Complexity Reference

| Structure / Model | Access | Search | Insertion | Deletion | Space Overhead | Memory Layout |
|---|---|---|---|---|---|---|
| **Static Array** | $\mathcal{O}(1)$ | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ (Zero) | Contiguous stack/data segment |
| **Dynamic Vector** | $\mathcal{O}(1)$ | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ amortized | $\mathcal{O}(n)$ | Spare capacity buffer | Contiguous heap buffer |
| **Singly Linked List** | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ at head/tail | $\mathcal{O}(1)$ at head | 1 pointer / node (8B on x64) | Dispersed heap nodes |
| **Doubly Linked List** | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ at head/tail | $\mathcal{O}(1)$ given pointer | 2 pointers / node (16B on x64) | Bidirectional heap nodes |
| **Circular List (CSLL/CDLL)** | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | 1–2 pointers / node | Ring topology (no `nullptr`) |
| **Stack (Array Backed)** | $\mathcal{O}(1)$ top | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ push | $\mathcal{O}(1)$ pop | Capacity bound | Contiguous buffer |
| **Queue (Circular Buffer)** | $\mathcal{O}(1)$ front | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ enqueue | $\mathcal{O}(1)$ dequeue | Fixed slot array | Ring buffer index wrap |
| **Binary Search Tree** | $\mathcal{O}(h)$ | $\mathcal{O}(h)$ | $\mathcal{O}(h)$ | $\mathcal{O}(h)$ | 2 pointers / node | Hierarchical tree nodes |

> *Note:* $h = \mathcal{O}(\log n)$ in balanced configurations, degrading to $\mathcal{O}(n)$ in degenerate skewed sequences.

---

## Syllabus & Topic Index

### 1. Contiguous Arrays & Matrix Algebra ([`Array/`](Array/))
Detailed theoretical proofs and memory models are documented in [`Array/Array Notes 00.md`](Array/Array%20Notes%2000.md).
- **Addressing Arithmetic:** Row-major index linearization: $\text{addr}(A[i][j]) = \text{base} + (i \cdot C + j) \times \text{sizeof}(T)$.
- **Pointer Decay:** Function argument decay mechanics (`T[]` $\rightarrow$ `T*`) and preservation via array references (`T(&)[N]`).
- **Implementations:** Dynamic array insertion, linear search, in-place sequence reversal, and set intersection.

### 2. Linked List Architectures ([`LinkedList/`](LinkedList/))
In-depth pointer mechanics, edge cases, and cycle detection are detailed in [`LinkedList/Notes.md`](LinkedList/Notes.md).
- **Singly Linked Lists (SLL):** Forward traversal, node creation, mid-list insertion, and iterative node reversal.
- **Doubly Linked Lists (DLL):** Bidirectional traversal, 4-pointer link updates, and node deletion without predecessor scans.
- **Circular Structures (CSLL / CDLL):** Non-null ring topologies for round-robin scheduling algorithms.
- **Floyd's Cycle-Finding Algorithm:** $\mathcal{O}(n)$ time, $\mathcal{O}(1)$ auxiliary space two-pointer detection ("Tortoise & Hare") and cycle-start derivation.

### 3. Stacks, Queues & Hierarchies ([`extras/`](extras/))
- **Stacks:** Dual implementations via fixed arrays and dynamic node chains (LIFO discipline).
- **Queues:** FIFO pipelines implemented as circular arrays (with modulo index wrap) and linked lists.
- **Binary Search Trees (BST):** Dynamic node allocation, recursive insertion, and sorted In-Order traversal.
- **Algorithmic Foundations:** Fast binary search ($\mathcal{O}(\log n)$), Euclidean GCD, tail-recursive factorial, and Fibonacci progressions.
- **Applied Capstone (`Project - Airlines.cpp`):** 525-line airline reservation and seat inventory management engine utilizing linked structures and file persistence.

### 4. University Laboratory Assignments ([`Lab-Task/`](Lab-Task/) & [`Assign/`](Assign/))
Formal coursework submissions covering pointer arithmetic, struct memory alignment, nested linked chains, and multi-tier sorting algorithms.

---

## Directory Layout

```
DSA-Code-Practice/
├── Array/                      # Contiguous array operations and deep architectural notes
│   ├── Array Notes 00.md       # Rigorous guide to memory formulas, VLA limits, and cache lines
│   ├── Array-Insertion.cpp     # Index-bounded insertion with element shifting
│   ├── Array-Linear-search.cpp # Sequential searching implementation
│   └── Array-reverse.cpp       # In-place two-pointer array reversal
├── LinkedList/                 # Node-based pointer structures
│   ├── Notes.md                # Node sizes, 64-bit padding, cycle detection, and smart pointers
│   ├── SLL Node Insertion.cpp  # Head, tail, and arbitrary position insertion
│   ├── Doubly LinkedList.cpp   # Two-way linked chains with prev/next pointers
│   ├── Circular LinkedList.cpp # Head-to-tail closed ring implementation
│   └── DLL Operations.cpp      # Full CRUD operations on doubly linked lists
├── extras/                     # Stacks, Queues, BSTs, Recursion, and Applied Systems
│   ├── Practice - BST Insertion Inorder.cpp
│   ├── Practice - Queue with Array.cpp
│   ├── Practice - Stack with LinkedList.cpp
│   ├── Practice - Binary Search.cpp
│   └── Project - Airlines.cpp  # Complete CLI flight seat reservation system
├── Lab-Task/                   # Structured laboratory assignments (Labs 01 – 03)
├── Assign/                     # Formal academic graded problem sets
└── Sorting/                    # Sorting algorithms (Quick Sort, etc.)
```

---

## Compilation & Toolchain

The codebase targets standard **C++17** and compiles warning-free under modern GCC, Clang, and MSVC toolchains.

### Compile with Modern Warnings
```bash
# Compile single unit with optimization and strict diagnostic flags
g++ -std=c++17 -Wall -Wextra -Wpedantic -O2 "Array/Array-reverse.cpp" -o array_reverse

# Execute binary
./array_reverse
```

### Memory Sanitization (AddressSanitizer)
To verify zero memory leaks, heap buffer overflows, or dangling pointer dereferences:
```bash
g++ -std=c++17 -fsanitize=address -g "LinkedList/Doubly LinkedList.cpp" -o dll_sanitized
./dll_sanitized
```

---

## Author & Academic Context

Maintained by **Hafiz Muhammad Saeed** ([@hmsaeed-dev](https://github.com/hmsaeed-dev)) — Department of Computer Science, **University of Engineering and Technology (UET), Taxila**.

*Part of the academic system records documented in the personal knowledge vault at `[[UET Taxila BSCS]]` and `[[Engineering & Systems MOC]]`.*
