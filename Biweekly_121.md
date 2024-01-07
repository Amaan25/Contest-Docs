# [LeetCode Biweekly Contest 121](https://leetcode.com/contest/biweekly-contest-121)


## 1. [Smallest Missing Integer Greater Than Sequential Prefix Sum](https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/)

Take the sum of numbers from the beginning of the array as long as the next number is 1 greater than current one. Now from the obtained sum find the next missing integer in nums.


## 2. [Minimum Number of Operations to Make Array XOR Equal to K](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/)

Calculate the bitwise XOR for all the elements in the array, and see how many bits differ from the bits in k. Take XOR with k and calculate number of set bits to find the number of different bits. 


## 3. [Minimum Number of Operations to Make X and Y Equal](https://leetcode.com/problems/minimum-number-of-operations-to-make-x-and-y-equal/)

[My solution](https://leetcode.com/problems/minimum-number-of-operations-to-make-x-and-y-equal/solutions/4518663/c-6-steps-beats-100)

All possible cases:

1. x <= y: here we have no choice but to increment x so the answer is y - x
2. x > y: we can look at the following paths
	a. Directly decrement to y (x - y steps)
	b. Go to next multiple of 11 >= x and divide by 11 (no need to go further than next multiple for calculating minimum ops)
	c. Go to previous multiple of 11 <= x and divide by 11
	d. Go to next multiple of 5 >= x and divide by 5
	e. Go to previous multiple of 5 <= x and divide by 5
After any of the steps from b to e we recursively calculate the number of operations.


## 4. [Count the Number of Powerful Integers](https://leetcode.com/problems/count-the-number-of-powerful-integers/)

Calculate Powerful Integers only for a given upper limit.
1. Convert s to number
2. Store remaining digits in x
3. Store digits of x in a vector/array z
4. If any number in array is greater than limit replace it with limit
5. Calculate number of powerful integers, eg. if number is 512 and limit is 7 then calculate as follows: 5x8x8 + 1x8 + 2
6. Return ans + 1 (+1 for including upper ceiling)
7. Final answer: powerful_ints(finish) - powerful_ints(start-1)

