In LeetCode 169: Majority Element, I implemented the Boyer–Moore Majority Vote Algorithm.
    
    Solution steps:
    - Start with `vote = 0`.
    - Iterate through the array.
    - When `vote == 0`, set the current element as the candidate.
    - If the next element equals the candidate, increment `vote`; otherwise decrement `vote`.
    - This effectively cancels out pairs of different elements.
    - At the end, the remaining candidate is the only possible majority.
    - Finally, verify the candidate by counting how many times it appears and checking if that count is greater than `n/2`.