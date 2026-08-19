# 3651. Minimum Cost Path with Teleportations

**Difficulty:** Hard  
[View on LeetCode](https://leetcode.com/problems/minimum-cost-path-with-teleportations/)

---

You are given a `m x n` 2D integer array `grid` and an integer `k`. You start at the top-left cell `(0, 0)` and your goal is to reach the bottom‐right cell `(m - 1, n - 1)`.

There are two types of moves available:

- **Normal move**: You can move right or down from your current cell `(i, j)`, i.e. you can move to `(i, j + 1)` (right) or `(i + 1, j)` (down). The cost is the value of the destination cell.

- **Teleportation**: You can teleport from any cell `(i, j)`, to any cell `(x, y)` such that `grid[x][y] <= grid[i][j]`; the cost of this move is 0. You may teleport at most `k` times.

Return the **minimum** total cost to reach cell `(m - 1, n - 1)` from `(0, 0)`.

**Example 1:**

**Input:** grid = [[1,3,3],[2,5,4],[4,3,5]], k = 2

**Output:** 7

**Explanation:**

Initially we are at (0, 0) and cost is 0.

<table style="border: 1px solid black;">
	<tbody>
		<tr>
			<th style="border: 1px solid black;">Current Position</th>
			<th style="border: 1px solid black;">Move</th>
			<th style="border: 1px solid black;">New Position</th>
			<th style="border: 1px solid black;">Total Cost</th>
		</tr>
		<tr>
			<td style="border: 1px solid black;"><code>(0, 0)</code></td>
			<td style="border: 1px solid black;">Move Down</td>
			<td style="border: 1px solid black;"><code>(1, 0)</code></td>
			<td style="border: 1px solid black;"><code>0 + 2 = 2</code></td>
		</tr>
		<tr>
			<td style="border: 1px solid black;"><code>(1, 0)</code></td>
			<td style="border: 1px solid black;">Move Right</td>
			<td style="border: 1px solid black;"><code>(1, 1)</code></td>
			<td style="border: 1px solid black;"><code>2 + 5 = 7</code></td>
		</tr>
		<tr>
			<td style="border: 1px solid black;"><code>(1, 1)</code></td>
			<td style="border: 1px solid black;">Teleport to <code>(2, 2)</code></td>
			<td style="border: 1px solid black;"><code>(2, 2)</code></td>
			<td style="border: 1px solid black;"><code>7 + 0 = 7</code></td>
		</tr>
	</tbody>
</table>

The minimum cost to reach bottom-right cell is 7.

**Example 2:**

**Input:** grid = [[1,2],[2,3],[3,4]], k = 1

**Output:** 9

**Explanation:**

Initially we are at (0, 0) and cost is 0.

<table style="border: 1px solid black;">
	<tbody>
		<tr>
			<th style="border: 1px solid black;">Current Position</th>
			<th style="border: 1px solid black;">Move</th>
			<th style="border: 1px solid black;">New Position</th>
			<th style="border: 1px solid black;">Total Cost</th>
		</tr>
		<tr>
			<td style="border: 1px solid black;"><code>(0, 0)</code></td>
			<td style="border: 1px solid black;">Move Down</td>
			<td style="border: 1px solid black;"><code>(1, 0)</code></td>
			<td style="border: 1px solid black;"><code>0 + 2 = 2</code></td>
		</tr>
		<tr>
			<td style="border: 1px solid black;"><code>(1, 0)</code></td>
			<td style="border: 1px solid black;">Move Right</td>
			<td style="border: 1px solid black;"><code>(1, 1)</code></td>
			<td style="border: 1px solid black;"><code>2 + 3 = 5</code></td>
		</tr>
		<tr>
			<td style="border: 1px solid black;"><code>(1, 1)</code></td>
			<td style="border: 1px solid black;">Move Down</td>
			<td style="border: 1px solid black;"><code>(2, 1)</code></td>
			<td style="border: 1px solid black;"><code>5 + 4 = 9</code></td>
		</tr>
	</tbody>
</table>

The minimum cost to reach bottom-right cell is 9.

**Constraints:**

- `2 <= m, n <= 80`
- `m == grid.length`
- `n == grid[i].length`
- `0 <= grid[i][j] <= 10^4`
- `0 <= k <= 10`
