# QuickSortWorseCase
The implementation of the algorithm Quick Sort where we detect the execution time for the worst case

### Compilation and Running

- Compilation: *gcc -std=c11 -O3 -lm -o quick_sort quick_sort.c*
- Running: *./quick_sort n r*
  - *n*: A positive integer, the number of elements in the input array.
  - *r*: A binary value (1 or 0), to allow the random pivot or not.

### Quick Sort Problem

Quick sort is one of the most popular sorting algorithm.
Many programming languages even C (function qsort()) include a built-in implementation.
However, in spite of its short average time complexity O(n log n), 
the algorithm takes O(n^2) time for the worst input case, which is too slow for practical use. 
