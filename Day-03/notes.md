# LeetCode 50: Pow(x, n)

Here I implemented **binary exponentiation**.  
Instead of multiplying $x$ by itself $n$ times (which takes $O(n)$ time),  
we use powers of 2, reducing the complexity to $O(\log n)$.

---

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

---

## Mathematical Visualization

$x^{13} = x^8 * x^4 * x^1$