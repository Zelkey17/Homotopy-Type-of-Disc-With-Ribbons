# Topological Classification of Ribbon Disks

This repository contains a **C++** program that analyzes a **word** (a string of lowercase Latin letters) and determines the corresponding **topological surface** obtained from a ribbon disk. The program computes two integers:

* **n**: the number of handles
* **b**: the number of boundary components

such that the surface is **homeomorphic to a sphere with *n* handles and *b* boundary components**.

## Compilation and Usage

Compile the program using any **C++ compiler**. For example:

```sh
g++ -o ribbon_disk ribbon_disk.cpp
./ribbon_disk
```

## Examples

| Input      | Output                                                                               |
| ---------- | -------------------------------------------------------------------------------------|
| `abazxzxb` | The ribbon disk is homeomorphic to a sphere with 2 handle and 1 boundary component.  |
| `abab`     | The ribbon disk is homeomorphic to a sphere with 1 handle and 1 boundary component.  |
| `abcabc`   | The ribbon disk is homeomorphic to a sphere with 1 handle and 2 boundary component.  |
| `aabb`     | The ribbon disk is homeomorphic to a sphere with 0 handle and 2 boundary component.  |
| `zxyxyz`   | The ribbon disk is homeomorphic to a sphere with 1 handle and 2 boundary component.  |

## Algorithm Overview

The program works as follows:

1. **Input Validation**

   * Ensure that each character in the input string appears exactly twice. Otherwise, throw an exception.

2. **Graph Construction**

   * Represent each letter occurrence as a vertex.
   * Add an edge connecting the two positions of the same character.
   * Add edges between consecutive positions in the string to form the ribbon structure.

3. **Connected Components (DFS)**

   * Perform a depth-first search (DFS) on the graph to count connected components.
   * Each connected component corresponds to one boundary component of the surface.

4. **Computation of Handles and Boundaries**

   The number of handles **n** and boundary components **b** are derived using the Euler characteristic of the surface. Specifically:
   - The number of handles is calculated as (n / 2 + 1 - b) / 2, where n is the length of the input string and b is the number of boundary components found.
   - The program ensures the minimum number of boundary components is 1 for an empty string.
    
5. **Output**

   * Print a message stating that the ribbon disk is homeomorphic to a sphere with the computed numbers of handles and boundary components.


## Background

This program was developed as part of the **"Discrete Structures and Algorithms in Topology"** course by **A. Skopenkov** and **A. Rukhovich** at Moscow Institute of Physics and Technology.  
Course website: [Введение в топологию](https://old.mccme.ru//circles//oim/home/combtop13.htm#fivt).
