# 3857. Minimum Cost to Split into Ones

**Difficulty:** Medium  
[View on LeetCode](https://leetcode.com/problems/minimum-cost-to-split-into-ones/)

---

You are given an integer `n`.

In one operation, you may split an integer `x` into two positive integers `a` and `b` such that `a + b = x`.

The cost of this operation is `a * b`.

Return an integer denoting the **minimum** total cost required to split the integer `n` into `n` ones.

**Example 1:**

**Input:** n = 3

**Output:** 3

**Explanation:**

One optimal set of operations is:

<table style="border: 1px solid black;">
	<tbody>
		<tr>
			<th style="border: 1px solid black;"><code>x</code></th>
			<th style="border: 1px solid black;"><code>a</code></th>
			<th style="border: 1px solid black;"><code>b</code></th>
			<th style="border: 1px solid black;"><code>a + b</code></th>
			<th style="border: 1px solid black;"><code>a * b</code></th>
			<th style="border: 1px solid black;">Cost</th>
		</tr>
		<tr>
			<td style="border: 1px solid black;">3</td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">3</td>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">2</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">1</td>
		</tr>
	</tbody>
</table>

Thus, the minimum total cost is `2 + 1 = 3`.

**Example 2:**

**Input:** n = 4

**Output:** 6

**Explanation:**

One optimal set of operations is:

<table style="border: 1px solid black;">
	<tbody>
		<tr>
			<th style="border: 1px solid black;"><code>x</code></th>
			<th style="border: 1px solid black;"><code>a</code></th>
			<th style="border: 1px solid black;"><code>b</code></th>
			<th style="border: 1px solid black;"><code>a + b</code></th>
			<th style="border: 1px solid black;"><code>a * b</code></th>
			<th style="border: 1px solid black;">Cost</th>
		</tr>
		<tr>
			<td style="border: 1px solid black;">4</td>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">4</td>
			<td style="border: 1px solid black;">4</td>
			<td style="border: 1px solid black;">4</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">1</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">1</td>
		</tr>
	</tbody>
</table>

Thus, the minimum total cost is `4 + 1 + 1 = 6`.

**Constraints:**

- `1 <= n <= 500`
