# QuickSortWorstCase
The implementation of the algorithm Quick Sort where we detect the execution time for the worst case

### Compilation and Running

- Compilation: *gcc -std=c11 -O3 -lm -o quick_sort quick_sort.c*
- Running: *time ./quick_sort n r*
  - *n*: A positive integer, the number of elements in the input array.
  - *r*: A binary value (1 or 0), to allow the random pivot or not.
  - We use a Linux command *time* to detect the overall execution time.

### Problem description

Quick Sort is one of the most popular sorting algorithms.
Many programming languages even C (function qsort()) include a built-in implementation of the algorithm.

Quick Sort takes average time O(n log n) if we assume the unordered array as input follows a uniform distribution over its all possible element permutations. However, if the distribution prefers worse cases or even the worst case, the algorithm will take O(n^2) time. The time cost is too high for practical use.

For Quick Sort, the worst case occurs when each pivot chosen by the algorithm always partitions the array into two sub-arrays of large size difference. For example, if the pivot is always selected the element of the lowest index in the current sub-array, then the worst case of *n*-element arrays is like:

- Array 1: *1, 2, ..., n*
- Array 2: *n, n - 1, ..., 1*

Hence, the problem aims at *the way of modifying Quick Sort to avoid O(n^2) time complexity for the worst case*

### Solution

Randomness is introduced to solve the problem.
The solution is simple:
Instead of selecting the pivot with a fixed position (e.g. the lowest or highest index) of a sub-array to be sorted,
we choose the pivot *uniformly at random*.

A much deeper math derivation tells us that the simple modification can bring the expected time complexity O(n log n) even if Quick Sort always faces the worst case.

Here this is my tiny implementation to experimence its correctness.

### Experiments

Without other statements, the time unit below is set *seconds*.

| Number of elements in the worst-case array (*n*) | Time for no random pivots (*r = 0*) | Time for random pivots (*r = 1*) |
| --------: | --------: | --------: |
| 1 | 	0.003 | 	0.003 | 
| 10 | 	0.003 | 	0.003 | 
| 100 | 	0.003 | 	0.003 | 
| 1000 | 	0.005 | 	0.003 | 
| 10000 | 	0.134 | 	0.005 | 
| 100000 | 	11.747 | 	0.023 | 
| 1000000 | 	1378.347 | 	0.122 | 

| Number of elements in the worst-case array (*n*) | Time for no random pivots (*r = 0*) | Time for random pivots (*r = 1*) |
| --------: | --------: | --------: |
| 10000 | 	0.136 | 	0.005 | 
| 20000 | 	0.47 | 	0.006 | 
| 30000 | 	1.061 | 	0.009 | 
| 40000 | 	1.926 | 	0.011 | 
| 50000 | 	2.943 | 	0.013 | 
| 60000 | 	4.232 | 	0.015 | 
| 70000 | 	5.793 | 	0.017 | 
| 80000 | 	7.535 | 	0.019 | 
| 90000 | 	9.563 | 	0.022 | 
| 100000 | 	11.771 | 	0.023 | 
