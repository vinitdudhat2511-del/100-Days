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
