/*Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.

Input:
- First line: an integer n

Output:
- Print the integer square root of n*/

#include <stdio.h>

int integer_sqrt(int n) {
    if (n == 0 || n == 1) return n;

    int left = 1, right = n;
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // To avoid overflow, compare mid with n / mid instead of mid*mid
        if (mid <= n / mid) {
            result = mid;      // mid is a candidate
            left = mid + 1;    // try larger
        } else {
            right = mid - 1;   // mid is too large
        }
    }

    return result;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    printf("%d\n", integer_sqrt(n));
    return 0;
}