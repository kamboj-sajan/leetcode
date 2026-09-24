# 3887. Incremental Even-Weighted Cycle Queries

**Difficulty:** Hard  
[View on LeetCode](https://leetcode.com/problems/incremental-even-weighted-cycle-queries/)

---

You are given a positive integer `n`.

There is an **undirected** graph with `n` nodes labeled from 0 to `n - 1`. Initially, the graph has no edges.

You are also given a 2D integer array `edges`, where `edges[i] = [u_i, v_i, w_i]` represents an edge between nodes `u_i` and `v_i` with weight `w_i`. The weight `w_i` is either 0 or 1.

Process the edges in `edges` in the given order. For each edge, add it to the graph only if, after adding it, the sum of the weights of the edges in **every** cycle in the resulting graph is **even**.

Return an integer denoting the number of edges that are successfully added to the graph.

**Example 1:**

**Input:** n = 3, edges = [[0,1,1],[1,2,1],[0,2,1]]

**Output:** 2

**Explanation:**

![image](https://assets.leetcode.com/uploads/2026/03/21/hmadizgovu.png)

- `[0, 1, 1]`: We add the edge between vertex 0 and vertex 1 with weight 1.
- `[1, 2, 1]`: We add the edge between vertex 1 and vertex 2 with weight 1.
- `[0, 2, 1]`: The edge between vertex 0 and vertex 2 (the dashed edge in the diagram) is not added because the cycle `0 - 1 - 2 - 0` has total edge weight `1 + 1 + 1 = 3`, which is an odd number.

**Example 2:**

**Input:** n = 3, edges = [[0,1,1],[1,2,1],[0,2,0]]

**Output:** 3

**Explanation:**

![image](https://assets.leetcode.com/uploads/2026/03/21/rbdgrefwok.png)

- `[0, 1, 1]`: We add the edge between vertex 0 and vertex 1 with weight 1.
- `[1, 2, 1]`: We add the edge between vertex 1 and vertex 2 with weight 1.
- `[0, 2, 0]`: We add the edge between vertex 0 and vertex 2 with weight 0.
- Note that the cycle `0 - 1 - 2 - 0` has total edge weight `1 + 1 + 0 = 2`, which is an even number.

**Constraints:**

- `3 <= n <= 5 * 10^4`
- `1 <= edges.length <= 5 * 10^4`
- `edges[i] = [u_i, v_i, w_i]`
- `0 <= u_i < v_i < n`
- All edges are distinct.
- `w_i = 0 or w_i = 1`
