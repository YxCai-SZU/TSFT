#include <stdbool.h>

/*@ requires 1 <= x <= 100;
    ensures \result <= x && \result <= 1;
    assigns \nothing;
 */
int func(int x) {
    int ans = 0;
    //@ assert 1 <= x <= 100;
    if (x == 1) {
        ans = 1;
    }
    //@ assert ans <= x;
    return ans;
}

/*@ requires 1 <= x <= 100;
    ensures \result ==> x % 2 == 0;
    ensures !\result ==> x % 2 == 1;
    assigns \nothing;
 */
bool is_even(int x) {
    bool ans = false;
    //@ assert 1 <= x <= 100;
    if (x % 2 == 0) {
        ans = true;
    }
    //@ assert ans ==> x % 2 == 0;
    return ans;
}

/*@ requires 1 <= n <= 100 && 1 <= m <= n && m <= 5;
    ensures \result >= 100 * (n - m) + 1900 * m;
    ensures \result <= 100 * (n - m) + 1900 * m + 100 * m;
    assigns \nothing;
 */
int func2(int n, int m) {
    int ans = 0;
    int i = 1;
    //@ assert 1 <= n <= 100 && 1 <= m <= n && m <= 5;
    
    /*@ loop invariant 1 <= i <= m + 1;
        loop invariant ans == 1900 * (i - 1);
        loop assigns i, ans;
        loop variant m - i;
     */
    while (i <= m) {
        ans += 1900;
        i += 1;
    }
    //@ assert ans == 1900 * m;
    
    i = 1;
    /*@ loop invariant 1 <= i <= n - m + 1;
        loop invariant ans == 1900 * m + 100 * (i - 1);
        loop assigns i, ans;
        loop variant n - m - i;
     */
    while (i <= (n - m)) {
        ans += 100;
        i += 1;
    }
    //@ assert ans == 1900 * m + 100 * (n - m);
    //@ assert ans >= 100 * (n - m) + 1900 * m;
    return ans;
}
