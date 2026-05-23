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


---

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


---

# LeetCode 50: Pow(x, n)

Here I implemented **binary exponentiation**.  
Instead of multiplying $x$ by itself $n$ times (which takes $O(n)$ time),  
we use powers of 2, reducing the complexity to $O(\log n)$.

## Algorithm

The key insight is to use the binary representation of $n$:
- Each bit in $n$ represents whether to include a power of 2
- We square $x$ repeatedly while dividing $n$ by 2
- When $n$ is odd, we multiply the result by the current power

**Strategy:**
1. Initialize `ans = 1`, `base = x`, `exp = n`
2. While `exp > 0`:
   - If `exp` is odd, multiply `ans` by current `base`
   - Square `base`
   - Divide `exp` by 2 (right shift)

## Dry Run Example

**Given:**  
$x = 2$  
$n = 13$ (binary: 1101)

**Initial:**  
ans = 1  
x = 2

**Iteration 1:**  
n = 13 (odd)  
ans = 1 × 2 = 2  
x = 2 × 2 = 4  
n = 6

**Iteration 2:**  
n = 6 (even)  
ans = 2  
x = 4 × 4 = 16  
n = 3

**Iteration 3:**  
n = 3 (odd)  
ans = 2 × 16 = 32  
x = 16 × 16 = 256  
n = 1

**Iteration 4:**  
n = 1 (odd)  
ans = 32 × 256 = 8192  
x = 256 × 256  
n = 0

**Final Answer:**  
$2^{13} = 8192$

## Mathematical Visualization

$x^{13} = x^8 \times x^4 \times x^1$

(Binary 1101 → powers of 8, 4, 1)

## Complexity

- **Time:** $O(\log n)$ - number of bits in $n$
- **Space:** $O(1)$ - only using constant variables


---

# LeetCode 121. Best Time to Buy and Sell Stock

Here I implemented a **single-pass greedy approach**.  
Given an array of stock prices, find the maximum profit by buying on one day and selling on a later day.  
You must buy before you sell, and you can complete at most one transaction.

## Algorithm

Instead of checking all pairs (which takes $O(n^2)$ time),  
we track the minimum price seen so far and calculate profit for each price in a single pass ($O(n)$ time).

**Strategy:**
- Keep track of the minimum price encountered so far (best buying opportunity)
- For each price, calculate profit if we sell at that price: $\text{profit} = \text{current price} - \text{min price}$
- Update the maximum profit whenever we find a better one
- Update the minimum price as we progress through the array

## Example

**Given:** prices = [7, 1, 5, 3, 6, 4]

**Iteration 1:** (price = 1)  
BestBuy = 7 (initial), MaxProfit = 0  
Update: BestBuy = min(7, 1) = 1

**Iteration 2:** (price = 5)  
BestBuy = 1, compare profit = 5 - 1 = 4  
MaxProfit = max(0, 4) = 4

**Iteration 3:** (price = 3)  
BestBuy = 1, compare profit = 3 - 1 = 2  
MaxProfit remains 4

**Iteration 4:** (price = 6)  
BestBuy = 1, compare profit = 6 - 1 = 5  
MaxProfit = max(4, 5) = 5 ✓

**Iteration 5:** (price = 4)  
BestBuy = 1, compare profit = 4 - 1 = 3  
MaxProfit remains 5

**Maximum Profit:** 5 (buy at 1, sell at 6)

## Complexity

- **Time:** $O(n)$ - single pass through the array
- **Space:** $O(1)$ - only using two variables


---

# LeetCode 11. Container With Most Water

Here I implemented the **Two-Pointer approach**.  
Given an array of heights, find the maximum area that can be formed between two vertical lines.  
The area is calculated as: $\text{Area} = \text{width} \times \text{min(height[left], height[right])}$

## Algorithm

Instead of checking all pairs (which takes $O(n^2)$ time),  
we use two pointers to efficiently find the maximum area in $O(n)$ time.

**Strategy:**
- Start with left pointer at index 0 and right pointer at the last index
- Calculate the area between these two lines
- Move the pointer pointing to the **smaller height** inward
- This is because moving the taller pointer can never increase the area (width decreases, height is limited by the shorter line)
- Keep track of the maximum area found

## Example

**Given:** heights = [1, 8, 6, 2, 5, 4, 8, 3, 7]

**Initial State:**  
left = 0 (height = 1), right = 8 (height = 7)  
width = 8, height = min(1, 7) = 1  
area = 8 × 1 = 8

**Next Iteration:**  
Move left pointer (since height[0]=1 < height[8]=7)  
left = 1 (height = 8), right = 8 (height = 7)  
width = 7, height = min(8, 7) = 7  
area = 7 × 7 = 49 ✓ (maximum)

**Continue...**  
Move right pointer (since height[1]=8 > height[8]=7)  
And so on until left >= right

**Maximum Area:** 49

## Complexity

- **Time:** $O(n)$ - single pass with two pointers
- **Space:** $O(1)$ - only using two pointers
