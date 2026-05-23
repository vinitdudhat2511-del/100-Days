# Leetcode 852. Peak Index in a Mountain Array

## Problem Overview
Find the index of the peak element in a mountain array. A mountain array is an array that strictly increases up to a peak, then strictly decreases. The peak is the element that is greater than its neighbors.

**Example:** 
- Array: `[0, 1, 0]` → Output: `1`
- Array: `[0, 2, 1, 0]` → Output: `1`
- Array: `[0, 10, 5, 2]` → Output: `1`

**Constraints:**
- Array has at least 3 elements
- Array is strictly increasing before the peak and strictly decreasing after the peak

---

## Key Insight
In a mountain array, we can use **binary search** to find the peak efficiently. At any point, we can determine which side of the mountain we're on by comparing the middle element with its neighbors.

---

## Algorithm Explanation

### Approach: Binary Search on Mountain

**Step 1:** Initialize pointers `st = 1` and `end = arr.size() - 2` (skip first and last elements since peak can't be there)

**Step 2:** In each iteration:
1. Calculate `mid = st + (end - st) / 2`
2. **Check three conditions:**
   - If `arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]`: Peak found, return `mid`
   - Else if `arr[mid-1] < arr[mid]`: We're on the increasing slope → search right
   - Else: We're on the decreasing slope → search left

**Step 3:** Continue until the peak is found

---

## Code Walkthrough

```cpp
int peakIndexInMountainArray(vector<int>& arr) {
    int st = 1;
    int end = arr.size() - 2;
    
    while (st <= end) {
        int mid = st + (end - st) / 2;
        
        // Peak element found
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            return mid;
        }
        // Increasing slope - peak is to the right
        else if (arr[mid - 1] < arr[mid]) {
            st = mid + 1;
        }
        // Decreasing slope - peak is to the left
        else {
            end = mid - 1;
        }
    }
    
    return -1;
}
```

### Logic Explanation:
- **Peak condition:** Element is greater than both neighbors
- **Increasing slope:** If `arr[mid-1] < arr[mid]`, we're still going up, so peak is ahead
- **Decreasing slope:** If the above condition fails, we must be going down, so peak is behind

---

## Example Trace

**Array:** `[0, 1, 2, 3, 4, 5, 3, 2, 1]`

| Iteration | st | end | mid | arr[mid] | arr[mid-1] | arr[mid+1] | Action |
|-----------|----|----|-----|----------|-----------|-----------|--------|
| 1 | 1 | 7 | 4 | 4 | 3 | 5 | 3 < 4, increasing → st = 5 |
| 2 | 5 | 7 | 6 | 5 | 4 | 3 | 4 < 5 && 5 > 3 → **Found at index 5** |

---

## Complexity Analysis

| Metric | Value |
|--------|-------|
| **Time Complexity** | O(log n) - Binary search divides search space by 2 each iteration |
| **Space Complexity** | O(1) - Only using constant extra space |

---

## Why This Works

1. **Mountain property:** Array is strictly increasing before peak, strictly decreasing after
2. **Binary search applicability:** We can determine which half contains the peak by checking the slope at mid
3. **Guaranteed convergence:** Each iteration eliminates at least half the search space

---

## Comparison with Linear Search

**Linear approach:** O(n) - Iterate through array until we find the peak
**Binary approach:** O(log n) - Much faster for large arrays

---

## Edge Cases Handled
- Peak at index 1 (array: `[0, 1, 0]`)
- Peak near the end (array: `[0, 1, 2, 3, 1]`)
- Very large arrays (binary search efficiency)
- Minimal valid array size (3 elements)
