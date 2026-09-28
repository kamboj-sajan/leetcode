# 4065. Rearrange Array by Removing Distinct Values

**Difficulty:** Easy  
[View on LeetCode](https://leetcode.com/problems/rearrange-array-by-removing-distinct-values/)

---

You are given an integer array `nums`.

You start with an **empty** array `ans`. Repeat the following operation until `nums` is **empty**:

- Identify **all** **distinct** values currently present in `nums`.
- Remove **one** occurrence of every **distinct** value currently in `nums`, and append those values to `ans` in **ascending** order.

Return the array `ans`.

**Example 1:**

**Input:** nums = [3,1,3,2,1,3]

**Output:** [1,2,3,1,3,3]

**Explanation:**

<table border="1" bordercolor="#ccc" cellpadding="5" cellspacing="0" style="border-collapse:collapse;">
	<thead>
		<tr>
			<th scope="col" style="text-align:center;">Operation</th>
			<th scope="col" style="text-align:center;">Appended to <code>ans</code></th>
			<th scope="col" style="text-align:center;"><code>nums</code> after</th>
			<th scope="col" style="text-align:center;"><code>ans</code> after</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="text-align:center;">1</td>
			<td style="text-align:center;">1, 2, 3</td>
			<td style="text-align:center;"><code>[3, 1, 3]</code></td>
			<td style="text-align:center;"><code>[1, 2, 3]</code></td>
		</tr>
		<tr>
			<td style="text-align:center;">2</td>
			<td style="text-align:center;">1, 3</td>
			<td style="text-align:center;"><code>[3]</code></td>
			<td style="text-align:center;"><code>[1, 2, 3, 1, 3]</code></td>
		</tr>
		<tr>
			<td style="text-align:center;">3</td>
			<td style="text-align:center;">3</td>
			<td style="text-align:center;"><code>[]</code></td>
			<td style="text-align:center;"><code>[1, 2, 3, 1, 3, 3]</code></td>
		</tr>
	</tbody>
</table>

`nums` is now empty, so the answer is `[1, 2, 3, 1, 3, 3]`.

**Example 2:**

**Input:** nums = [7,7,4,4,4]

**Output:** [4,7,4,7,4]

**Explanation:**

<table border="1" bordercolor="#ccc" cellpadding="5" cellspacing="0" style="border-collapse:collapse;">
	<thead>
		<tr>
			<th scope="col" style="text-align:center;">Operation</th>
			<th scope="col" style="text-align:center;">Appended to <code>ans</code></th>
			<th scope="col" style="text-align:center;"><code>nums</code> after</th>
			<th scope="col" style="text-align:center;"><code>ans</code> after</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="text-align:center;">1</td>
			<td style="text-align:center;">4, 7</td>
			<td style="text-align:center;"><code>[7, 4, 4]</code></td>
			<td style="text-align:center;"><code>[4, 7]</code></td>
		</tr>
		<tr>
			<td style="text-align:center;">2</td>
			<td style="text-align:center;">4, 7</td>
			<td style="text-align:center;"><code>[4]</code></td>
			<td style="text-align:center;"><code>[4, 7, 4, 7]</code></td>
		</tr>
		<tr>
			<td style="text-align:center;">3</td>
			<td style="text-align:center;">4</td>
			<td style="text-align:center;"><code>[]</code></td>
			<td style="text-align:center;"><code>[4, 7, 4, 7, 4]</code></td>
		</tr>
	</tbody>
</table>

`nums` is now empty, so the answer is `[4, 7, 4, 7, 4]`.

**Constraints:**

- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 100`
