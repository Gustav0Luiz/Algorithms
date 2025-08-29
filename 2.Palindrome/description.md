# 9. Palindrome Number

Given an integer `x`, return `true` if `x` is a **palindrome** and `false` otherwise.  
A number is a palindrome if it reads the same backward as forward.

---

### Example 1:
**Input:** `x = 121`  
**Output:** `true`  
**Explanation:** `121` reads the same left to right and right to left.

### Example 2:
**Input:** `x = -121`  
**Output:** `false`  
**Explanation:** Left to right, it reads `-121`; right to left, it becomes `121-`. Not a palindrome.

### Example 3:
**Input:** `x = 10`  
**Output:** `false`  
**Explanation:** Right to left, it reads `01`. Not a palindrome.

---

### Constraints
- `-2^31 <= x <= 2^31 - 1`

---

### Follow-up
Can you solve it **without converting the integer to a string**?

---

## Approaches

1) **String conversion (simple)**
- Convert `x` to `std::string`, compare with its reverse.
- Note: negatives return `false` immediately.
- **Complexity:** `O(d)` time and `O(d)` space, where `d` is the number of digits.

2) **Without string (reversing half) — recommended**
- Negative numbers are not palindromes.  
- Numbers ending with `0` (except `0` itself) are not palindromes.  
- Reverse **only the right half** of the number to avoid overflow:
  - While `x > rev`, do `rev = rev*10 + x%10` and `x /= 10`.
  - At the end, palindrome if `x == rev` (even length) or `x == rev/10` (odd length).
- **Complexity:** `O(d)` time and `O(1)` space.
