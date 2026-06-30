### B - Interesting Drink

**Problem:**
The problem requires us to find how many shops Vasiliy can buy a bottle from. We are given an integer `n`, which is the number of shops in the city that sell Vasiliy’s favorite drink. After that, we are given a list of integers representing the prices in each shop. We are also given the number of days Vasiliy plans to drink, followed by a single integer per day representing the amount of money he has.

For each day, we must determine how many shops Vasiliy can visit where the price of the drink is less than or equal to his available coins.

---

**Idea:**
The solution I came up with implements a divide and conquer strategy that I coded from scratch. I developed the idea by visualizing a sorted array, then repeatedly dividing it in half and checking whether the middle value is greater than or equal to the input value.

Depending on the result of the comparison using relational operators, the search direction is adjusted accordingly. The process continues until a base case is reached, where the function identifies the boundary where Vasiliy can still afford a drink. This boundary is then used to determine how many shops he can visit.

---

**Solution and Implementation:**
The array is first sorted in ascending order. For each query (each day), we perform a recursive divide and conquer (binary search) to find the boundary index where the prices exceed the given number of coins. While traversing, we keep track of the number of valid shops using a reference variable.

Edge cases are handled separately: if the coins are less than the smallest price, the result is 0; if the coins are greater than or equal to the largest price, the result is the size of the array. Otherwise, the divide and conquer function narrows down the search space until it reaches the correct boundary and returns the total count of shops Vasiliy can afford.

---
