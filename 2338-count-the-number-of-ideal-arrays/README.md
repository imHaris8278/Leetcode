# 2338. Count the Number of Ideal Arrays  
**Solved**  
**Hard**  
**Topics**: Math, Dynamic Programming, Combinatorics  
**Companies**: —  

---

You are given two integers `n` and `maxValue`, which describe the properties of an **ideal array**.

A **0-indexed integer array** `arr` of length `n` is considered **ideal** if the following conditions hold:

- Every `arr[i]` is a value from `1` to `maxValue`, for `0 <= i < n`.
- Every `arr[i]` is divisible by `arr[i - 1]`, for `0 < i < n`.

Your task is to return the **number of distinct ideal arrays** of length `n`.  
Since the answer may be very large, **return it modulo 10⁹ + 7**.

---

### Example 1:

**Input:**  
`n = 2, maxValue = 5`  
**Output:**  
`10`  

**Explanation:**  
The following are the possible ideal arrays:  
- Arrays starting with 1 (5 arrays): `[1,1]`, `[1,2]`, `[1,3]`, `[1,4]`, `[1,5]`  
- Arrays starting with 2 (2 arrays): `[2,2]`, `[2,4]`  
- Arrays starting with 3 (1 array): `[3,3]`  
- Arrays starting with 4 (1 array): `[4,4]`  
- Arrays starting with 5 (1 array): `[5,5]`  
Total = `5 + 2 + 1 + 1 + 1 = 10`

---

### Example 2:

**Input:**  
`n = 5, maxValue = 3`  
**Output:**  
`11`  

**Explanation:**  
The following are the possible ideal arrays:  
- Arrays starting with 1 (9 arrays):  
  - With only 1s: `[1,1,1,1,1]`  
  - With 2s: `[1,1,1,1,2]`, `[1,1,1,2,2]`, `[1,1,2,2,2]`, `[1,2,2,2,2]`  
  - With 3s: `[1,1,1,1,3]`, `[1,1,1,3,3]`, `[1,1,3,3,3]`, `[1,3,3,3,3]`  
- Arrays starting with 2 (1 array): `[2,2,2,2,2]`  
- Arrays starting with 3 (1 array): `[3,3,3,3,3]`  
Total = `9 + 1 + 1 = 11`

---

### Constraints:

- `2 <= n <= 10⁴`  
- `1 <= maxValue <= 10⁴`

---

### Hints:
1. Use dynamic programming to build arrays of increasing length while satisfying the divisibility condition.
2. Think in terms of sequences ending in different values.
3. Factorization and combinatorics (binomial coefficients) can help optimize the solution.

---

### Follow-up:  
Can you solve this using **precomputed factorials** and **prime factorization** to speed up the count?

---

**Accepted:**  
25.5K+  
**Submissions:**  
55.7K+  
**Acceptance Rate:**  
~45.8%

---
