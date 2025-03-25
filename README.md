# Homotopy Type of Disc with Ribbons 

This repository contains a **C++** program that analyzes the **homotopy type of a word** (a string of lowercase Latin letters) and determines its **topological structure** as a surface with handles and boundary components.  

Given an input string, the program computes integers **n** (the number of handles) and **b** (the number of boundary components) such that the surface is **homeomorphic to a sphere with n handles and b boundary components**.

## Compilation and Usage

You can compile the program using any **C++ compiler**.  
For example, using **g++**:
```sh
g++ -o homotopy homotopy.cpp
./homotopy
```
## Examples

| Input  | Output |
|--------|------------------------------------|
| 'abazxzxb'  | The ribbon disk is homeomorphic to a sphere with 2 handles and 1 holes. |
| 'abab' | The ribbon disk is homeomorphic to a sphere with 1 handles and 1 holes. |
| 'abcabc' | The ribbon disk is homeomorphic to a sphere with 1 handles and 2 holes. |
| 'aabb' | The ribbon disk is homeomorphic to a sphere with 0 handles and 2 holes. |
| 'zxyxyz' | The ribbon disk is homeomorphic to a sphere with 1 handles and 2 holes. |

## Algorithm

The program works as follows:

1. **Input validation:**  
   It first checks that each character in the input string appears exactly twice. If this condition is not satisfied, the program throws an exception.

2. **Graph construction:**  
   It constructs a graph where each character corresponds to two vertices. The vertices are connected based on the structure of the string, and edges are added between positions of the same character.

3. **Depth-first search (DFS):**  
   The program uses DFS to find connected components in the graph. Each connected component corresponds to a boundary component in the topological surface.

4. **Homotopy calculation:**  
   The number of handles **n** and boundary components **b** are derived using the Euler characteristic of the surface. Specifically:
   - The number of handles is calculated as `(n / 2 + 1 - cnt) / 2`, where `n` is the length of the input string and `cnt` is the number of boundary components found.
   - The program ensures the minimum number of boundary components is 1 for an empty string.


## Background

This program was developed as part of the **"Discrete Structures and Algorithms in Topology"** course by **A.B. Skopenkov** at Moscow Institute of Physics and Technology.  
Course website: [Введение в топологию](https://old.mccme.ru//circles//oim/home/combtop13.htm#fivt).
