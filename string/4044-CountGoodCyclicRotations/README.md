# 4044. Count Good Cyclic Rotations

**Difficulty:** Medium  
[View on LeetCode](https://leetcode.com/problems/count-good-cyclic-rotations/)

---

You are given an integer array `nums` of even length `n`.

A **cyclic rotation** of `nums` is obtained by choosing a prefix of `nums` whose length is between 0 and `n - 1` (inclusive), and moving it to the end of the array while preserving the order of all elements.

A cyclic rotation is **good** if the sum of its first `n / 2` elements is **strictly greater** than the sum of its last `n / 2` elements.

Return the number of cyclic rotations of `nums` that are good.

**Example 1:**

**Input:** nums = [1,2,3,4,5,6]

**Output:** 3

**Explanation:**

The cyclic rotations of `nums` are:

<table>
	<thead>
		<tr>
			<th style="text-align: center; padding: 6px 12px;">Cyclic rotation</th>
			<th style="text-align: center; padding: 6px 12px;">Sum of first <code>n / 2</code> elements</th>
			<th style="text-align: center; padding: 6px 12px;">Sum of last <code>n / 2</code> elements</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="text-align: center; padding: 6px 12px;"><code>[1, 2, 3, 4, 5, 6]</code></td>
			<td style="text-align: center; padding: 6px 12px;"><code>1 + 2 + 3 = 6</code></td>
			<td style="text-align: center; padding: 6px 12px;"><code>4 + 5 + 6 = 15</code></td>
		</tr>
		<tr>
			<td style="text-align: center; padding: 6px 12px;"><code>[2, 3, 4, 5, 6, 1]</code></td>
			<td style="text-align: center; padding: 6px 12px;"><code>2 + 3 + 4 = 9</code></td>
			<td style="text-align: center; padding: 6px 12px;"><code>5 + 6 + 1 = 12</code></td>
		</tr>
		<tr>
			<td style="text-align: center; padding: 6px 12px;"><code>[3, 4, 5, 6, 1, 2]</code></td>
			<td style="text-align: center; padding: 6px 12px;"><code>3 + 4 + 5 = 12</code></td>
			<td style="text-align: center; padding: 6px 12px;"><code>6 + 1 + 2 = 9</code></td>
		</tr>
		<tr>
			<td style="text-align: center; padding: 6px 12px;"><code>[4, 5, 6, 1, 2, 3]</code></td>
			<td style="text-align: center; padding: 6px 12px;"><code>4 + 5 + 6 = 15</code></td>
			<td style="text-align: center; padding: 6px 12px;"><code>1 + 2 + 3 = 6</code></td>
		</tr>
		<tr>
			<td style="text-align: center; padding: 6px 12px;"><code>[5, 6, 1, 2, 3, 4]</code></td>
			<td style="text-align: center; padding: 6px 12px;"><code>5 + 6 + 1 = 12</code></td>
			<td style="text-align: center; padding: 6px 12px;"><code>2 + 3 + 4 = 9</code></td>
		</tr>
		<tr>
			<td style="text-align: center; padding: 6px 12px;"><code>[6, 1, 2, 3, 4, 5]</code></td>
			<td style="text-align: center; padding: 6px 12px;"><code>6 + 1 + 2 = 9</code></td>
			<td style="text-align: center; padding: 6px 12px;"><code>3 + 4 + 5 = 12</code></td>
		</tr>
	</tbody>
</table>

The first half has a greater sum than the second half for 3 rotations. Thus, the answer is 3.

**Example 2:**

**Input:** nums = [1,2,1,2]

**Output:** 0

**Explanation:**

The cyclic rotations of `nums` are:

<table>
	<thead>
		<tr>
			<th style="text-align: center; padding: 6px 12px;">Cyclic rotation</th>
			<th style="text-align: center; padding: 6px 12px;">Sum of first <code>n / 2</code> elements</th>
			<th style="text-align: center; padding: 6px 12px;">Sum of last <code>n / 2</code> elements</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="text-align: center; padding: 6px 12px;"><code>[1, 2, 1, 2]</code></td>
			<td style="text-align: center; padding: 6px 12px;"><code>1 + 2 = 3</code></td>
			<td style="text-align: center; padding: 6px 12px;"><code>1 + 2 = 3</code></td>
		</tr>
		<tr>
			<td style="text-align: center; padding: 6px 12px;"><code>[2, 1, 2, 1]</code></td>
			<td style="text-align: center; padding: 6px 12px;"><code>2 + 1 = 3</code></td>
			<td style="text-align: center; padding: 6px 12px;"><code>2 + 1 = 3</code></td>
		</tr>
		<tr>
			<td style="text-align: center; padding: 6px 12px;"><code>[1, 2, 1, 2]</code></td>
			<td style="text-align: center; padding: 6px 12px;"><code>1 + 2 = 3</code></td>
			<td style="text-align: center; padding: 6px 12px;"><code>1 + 2 = 3</code></td>
		</tr>
		<tr>
			<td style="text-align: center; padding: 6px 12px;"><code>[2, 1, 2, 1]</code></td>
			<td style="text-align: center; padding: 6px 12px;"><code>2 + 1 = 3</code></td>
			<td style="text-align: center; padding: 6px 12px;"><code>2 + 1 = 3</code></td>
		</tr>
	</tbody>
</table>

No cyclic rotation is good because the two sums are equal for every rotation. Thus, the answer is 0.

**Constraints:**

- `2 <= n == nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
- `n` is even.
