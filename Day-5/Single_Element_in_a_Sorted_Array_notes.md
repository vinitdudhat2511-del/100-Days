# Leetcode 540. Single Element in a Sorted Array

## Problem Overview
Find the single element in a sorted array where every other element appears exactly twice. All elements appear in pairs except for one element which appears only once.

**Example:** 
- Array: `[1, 1, 2, 3, 3, 4, 4, 8, 8]` → Output: `2`
- Array: `[3, 3, 7, 7, 10, 11, 11]` → Output: `10`

**Constraints:**
- Array is sorted
- All elements appear twice except one
- Array length is odd

---

## Key Insight
In a sorted array with pairs, the **index of paired elements follows a pattern**:
- In the first half (before single element): left element of pair is at **even index**, right is at **odd index**
- In the second half (after single element): left element of pair is at **odd index**, right is at **even index**

We can use this pattern with **binary search** to find which half contains the single element.

---

## Algorithm Explanation

### Approach: Binary Search with Index Parity

**Step 1:** Handle edge cases (n=1, check boundaries)

**Step 2:** Initialize pointers `st = 0` and `end = n - 1`

**Step 3:** In each iteration:
1. Calculate `mid = st + (end - st) / 2`
2. **Check if mid is the single element:** `nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]`
3. **For even index mid:**
   - If `nums[mid] == nums[mid-1]`: Pair is broken (single on left) → search left
   - Else: Pair is intact (single on right) → search right
4. **For odd index mid:**
   - If `nums[mid] == nums[mid-1]`: Pair is intact (single on right) → search right
   - Else: Pair is broken (single on left) → search left

---


### Logic Explanation:

**For even index (0, 2, 4, ...):**
- Normal case: left element at even index, right at odd index
- If `nums[mid] == nums[mid-1]`: Pattern is broken early → single is on left half
- If `nums[mid] != nums[mid-1]`: Pattern continues → single is on right half

**For odd index (1, 3, 5, ...):**
- Normal case: even-indexed element is first of pair, odd-indexed is second
- If `nums[mid] == nums[mid-1]`: Pattern is still intact → single is on right half
- If `nums[mid] != nums[mid-1]`: Pattern is broken → single is on left half

---

## Example Trace

**Array:** `[1, 1, 2, 3, 3, 4, 4, 8, 8]`

| Iteration | st | end | mid | nums[mid] | Index Parity | Comparison | Action |
|-----------|----|----|-----|-----------|--------------|-----------|--------|
| 1 | 0 | 8 | 4 | 3 | Even | nums[4]=3 ≠ nums[3]=3 | Single on right → st = 5 |
| 2 | 5 | 8 | 6 | 4 | Even | nums[6]=4 == nums[5]=4 | Single on left → end = 5 |
| 3 | 5 | 5 | 5 | 3 | Odd | nums[5]=3 != nums[4]=3 && nums[5]!=nums[6] | **Found at index 5... wait, let me recalculate** |

Actually, let me trace more carefully:
- Index 0,1: [1,1] - pair
- Index 2: [2] - SINGLE
- Index 3,4: [3,3] - pair
- Index 5,6: [4,4] - pair
- Index 7,8: [8,8] - pair

| Iteration | st | end | mid | nums[mid] | mid%2 | nums[mid]==nums[mid-1] | Action |
|-----------|----|----|-----|-----------|-------|------------------------|--------|
| 1 | 0 | 8 | 4 | 3 | 0(even) | 3==3? YES | Single on left → end = 3 |
| 2 | 0 | 3 | 1 | 1 | 1(odd) | 1==1? YES | Single on right → st = 2 |
| 3 | 2 | 3 | 2 | 2 | 0(even) | 2==1? NO | Single on right → st = 3 |
| 4 | 3 | 3 | 3 | 3 | 1(odd) | 3==2? NO | Single on left → end = 2 |
| Loop ends (st > end) | - | - | - | - | - | - | **Found element 2 at index 2** |

---

## Complexity Analysis

| Metric | Value |
|--------|-------|
| **Time Complexity** | O(log n) - Binary search in each step |
| **Space Complexity** | O(1) - Only using constant extra space |

---

## Why This Works

1. **Sorted array with pairs:** Predictable pattern of indices
2. **Index parity tells the story:** Position of elements reveals if pair is intact or broken
3. **Binary elimination:** Each iteration eliminates at least half the search space
4. **Guaranteed single element:** Exactly one element doesn't appear twice

---

## Alternative Approach 1: Linear Search
```cpp
// Naive approach: O(n)
for (int i = 0; i < n; i += 2) {
    if (i + 1 >= n || nums[i] != nums[i + 1]) {
        return nums[i];
    }
}
```

**Complexity:** O(n) time, O(1) space  
Binary search is O(log n) vs O(n) for linear, much more efficient!

---

## Alternative Approach 2: XOR Bit Manipulation

This approach exploits the property that **XOR of two identical numbers is 0**, and **XOR of any number with 0 is the number itself**.

```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = ans ^ nums[i];  // XOR all elements
        }
        return ans;
    }
};
```

### How It Works:
- Since all elements appear exactly twice except one, when we XOR all elements together:
  - Each pair: `a ^ a = 0`
  - All pairs cancel out: `0 ^ 0 ^ ... ^ 0 = 0`
  - Single element remains: `0 ^ single = single`

### Example:
**Array:** `[1, 1, 2, 3, 3, 4, 4, 8, 8]`
- `0 ^ 1 ^ 1 = 0` (pair cancels)
- `0 ^ 2 = 2` (single element)
- `2 ^ 3 ^ 3 = 2` (pair cancels, 2 remains)
- `2 ^ 4 ^ 4 = 2` (pair cancels, 2 remains)
- `2 ^ 8 ^ 8 = 2` (pair cancels, 2 remains)
- **Result:** `2`

### Complexity:
- **Time Complexity:** O(n) - Must XOR all elements
- **Space Complexity:** O(1) - Only one variable

### Pros and Cons:
| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| Binary Search | O(log n) | O(1) | **Optimal** - Exploits sorted property | Complex logic |
| XOR | O(n) | O(1) | Simple & elegant | Ignores sorted property, slower |
| Linear | O(n) | O(1) | Simple | Slowest, ignores sorted property |

**Note:** The XOR approach works for ANY array (doesn't need to be sorted), making it more general but less efficient for this specific problem.

---

## Edge Cases Handled
- Single element array (`n == 1`)
- Single element at index 0
- Single element at index n-1
- Single element in the middle
- Large arrays (binary search efficiency)
