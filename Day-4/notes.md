# LeetCode 238. Product of Array Except Self

Here I implemented a **two-pass prefix-suffix approach**.  
Given an array `nums`, return an array `answer` where `answer[i]` is the product of all elements except `nums[i]`.  
Cannot use division, and must run in $O(n)$ time.

## Algorithm

The key insight is to use **prefix and suffix products**:
- **Prefix:** Product of all elements to the left of position $i$
- **Suffix:** Product of all elements to the right of position $i$
- **Result:** `answer[i] = prefix[i] × suffix[i]`

This approach solves the problem in two passes with $O(1)$ extra space (excluding the output array).

**Strategy:**
1. **First Pass (Left to Right):** Store the product of all elements to the left in `answer[i]`
   - `answer[0] = 1` (no elements to the left)
   - `answer[i] = answer[i-1] × nums[i-1]`

2. **Second Pass (Right to Left):** Multiply by the product of all elements to the right
   - Track `suffix = product of all elements to the right`
   - `answer[i] *= suffix`
   - Update `suffix *= nums[i+1]` for next iteration

## Example

**Given:** nums = [1, 2, 3, 4]

**After First Pass (Prefix):**  
- `answer[0] = 1` (no left elements)
- `answer[1] = 1 × 1 = 1`
- `answer[2] = 1 × 2 = 2`
- `answer[3] = 2 × 3 = 6`

Result after first pass: [1, 1, 2, 6]

**Second Pass (Multiply by Suffix):**  
suffix = 1, i = 2:
- suffix = 1 × 4 = 4
- `answer[2] = 2 × 4 = 8`

i = 1:
- suffix = 4 × 3 = 12
- `answer[1] = 1 × 12 = 12`

i = 0:
- suffix = 12 × 2 = 24
- `answer[0] = 1 × 24 = 24`

**Final Answer:** [24, 12, 8, 6]

**Verification:**
- answer[0] = 2 × 3 × 4 = 24 ✓
- answer[1] = 1 × 3 × 4 = 12 ✓
- answer[2] = 1 × 2 × 4 = 8 ✓
- answer[3] = 1 × 2 × 3 = 6 ✓

## Complexity

- **Time:** $O(n)$ - two passes through the array
- **Space:** $O(1)$ - only using constant variables (not counting output array)




# Leetcode 136. Single Number

Here I implemented a **XOR (Bitwise Exclusive OR) approach**.  
Given an array where every element appears twice except one, find the single number.  
Must run in $O(n)$ time and use $O(1)$ space without modifying the input.

## Algorithm

The key insight is the **XOR property**: 
- `a ^ a = 0` (XOR of identical numbers is 0)
- `a ^ 0 = a` (XOR with 0 gives the number itself)
- `XOR is commutative and associative` (order doesn't matter)

When we XOR all numbers together:
- Pairs cancel out to 0
- The single number remains

**Strategy:**
1. Initialize `answer = 0`
2. XOR each number with `answer`
3. All pairs will cancel out, leaving only the single number

## Example

**Given:** nums = [4, 1, 2, 1, 2]

**Step-by-step XOR:**
- answer = 0
- answer = 0 ^ 4 = 4
- answer = 4 ^ 1 = 5
- answer = 5 ^ 2 = 7
- answer = 7 ^ 1 = 6 (the pair of 1's partially cancels)
- answer = 6 ^ 2 = 4 (the pair of 2's cancels, leaving 4) ✓

**Alternative visualization (commutative):**
- (4 ^ 4) ^ (1 ^ 1) ^ (2 ^ 2) = 0 ^ 0 ^ 0 = 0
- Wait, this doesn't match. Let me recalculate...
- Actually: 4 ^ 1 ^ 2 ^ 1 ^ 2
- Rearrange: (4) ^ (1 ^ 1) ^ (2 ^ 2)
- = 4 ^ 0 ^ 0 = 4 ✓

## Why XOR Works

XOR at the bit level:
- `0 ^ 0 = 0`
- `0 ^ 1 = 1`
- `1 ^ 0 = 1`
- `1 ^ 1 = 0`

For each bit position, if it appears an even number of times (in pairs), XOR results in 0. If it appears an odd number of times (single number), XOR results in 1.

**Example with bits:** nums = [2, 2, 1]
- 2 = 10 (binary)
- 2 = 10
- 1 = 01

XOR all:
```
  10
  10
^ 01
----
  01  = 1 ✓
```

## Complexity

- **Time:** $O(n)$ - single pass through the array
- **Space:** $O(1)$ - only using one variable