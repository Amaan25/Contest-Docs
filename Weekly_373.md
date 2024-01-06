# [LeetCode Weekly Contest 373] (https://leetcode.com/contest/weekly-contest-373/)

## 1. [Matrix Similarity After Cyclic Shifts] (https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/)

For every element in the matrix, check if mat\[i\]\[j\] == mat\[i\]\[(j+k)%n\] where n = mat\[0\].size()

## 2. [Count Beautiful Substrings I] (https://leetcode.com/problems/count-beautiful-substrings-i/)

Brute force: for every pair i, j, calculate the number of vowels and consonents, add 1 to ans if vowels == consonents and vowels\*consonents%k == 0

## 3. [Make Lexicographically Smallest Array by Swapping Elements] (https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/)

Similar to: [Smallest String With Swaps] (https://leetcode.com/problems/smallest-string-with-swaps/), for a given string and given pair of indices that can be swapped, find the lexicographically smallest string possible.

Form connected components using the pair of indices, every element in the component can be swapped by any other character in the same component. Form lexicographically smallest string possible using only the characters in a component, put its characters (in order) in the original string at locations of elements in the given component.

Similarly, form components in which every node has a distance <= limit with atleast one other node in the component. These nodes can be swapped with any other node in the component. This can be done in O(nlogn) by sorting ids vector with respect to nums vector values, now all components will be grouped together in ids vector.

1	2	3  \|	8	9	10	\|	15	17	19 (three components if limit is 2)

Sort each component and put the values in the result array at original locations of the component

eg. Original component ids and corresponding nums values

ids: 	2   3   5	8
nums: 	3   7   4   6

After sorting
sorted: 	2   5   8	3
nums: 		3   4   6   7

```
	res[ids[i]] = nums[sorted[i]];
```

Learned:
1. Simplified DSU approach with only find function:
```
int find(vector<int>& ds, int i) {
	return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
}
```
2. Sorting one vector based on values of another vector:
```
	sort(begin(a), end(a), [&](int i, int j) { return nums[i] < nums[j];});
```

## 4. [Count Beautiful Substrings II] (https://leetcode.com/problems/count-beautiful-substrings-ii/)