# Leetcode 33. Search in Rotated Sorted Array

## Problem Overview
Find the index of a target value in a rotated sorted array. If the target is not found, return -1.

**Example:** 
- Array: `[4, 5, 6, 7, 0, 1, 2]`, Target: `0` → Output: `4`
- Array: `[4, 5, 6, 7, 0, 1, 2]`, Target: `3` → Output: `-1`

---

## Key Insight
In a rotated sorted array, **one half is always sorted** (left or right). We can use this property with binary search to efficiently narrow down the search space.

---

## Algorithm Explanation

### Approach: Modified Binary Search

**Step 1:** Initialize two pointers `st` (start) and `end`

**Step 2:** In each iteration:
1. Calculate `mid = st + (end - st) / 2`
2. If `nums[mid] == target`, return `mid`
3. **Determine which half is sorted:**
   - If `nums[st] <= nums[mid]`: Left half is sorted
   - Else: Right half is sorted
4. **Check if target lies in the sorted half:**
   - If yes: search that half
   - If no: search the other half

**Step 3:** Repeat until element is found or range is exhausted

---

## Code Walkthrough

### Main Logic:
```cpp
while (st <= end) {
    int mid = st + (end - st) / 2;
    
    if (nums[mid] == target) {
        return mid;  // Found!
    }
    
    // Check if LEFT half is sorted
    if (nums[st] <= nums[mid]) {
        // If target is in left sorted half, search left
        if (nums[st] <= target && target <= nums[mid]) {
            end = mid - 1;
        } else {
            // Otherwise search right
            st = mid + 1;
        }
    }
    // RIGHT half must be sorted
    else {
        // If target is in right sorted half, search right
        if (nums[mid] <= target && target <= nums[end]) {
            st = mid + 1;
        } else {
            // Otherwise search left
            end = mid - 1;
        }
    }
}
```

---

## Complexity Analysis

| Metric | Value |
|--------|-------|
| **Time Complexity** | O(log n) - Binary search in each step |
| **Space Complexity** | O(1) - Only using constant extra space |

---

## Why This Works

1. **Array is rotated:** There's a pivot point where the array "breaks"
2. **Binary search property:** We can eliminate half the array in each iteration
3. **One half is always sorted:** This guarantee allows us to make decisions about which half to search

**Example trace with `[4, 5, 6, 7, 0, 1, 2]`, target = `0`:**
- Iteration 1: `st=0, end=6, mid=3, nums[mid]=7` → Left sorted, target not in left → search right
- Iteration 2: `st=4, end=6, mid=5, nums[mid]=1` → Right sorted, target in range → search right  
- Iteration 3: `st=4, end=4, mid=4, nums[mid]=0` → Found! Return `4`

---

## Edge Cases Handled
- Target is at the rotation point
- Target is in the first half (before rotation)
- Target is in the second half (after rotation)
- Target doesn't exist in array
- Single element array
