#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == true <==> (n % 3 == 0 || n % 5 == 0);
    assigns \nothing;
*/
bool func(int n) {
    bool is_divisible_by_3;
    bool is_divisible_by_5;
    int temp_n;

    // Check divisibility by 3
    is_divisible_by_3 = false;
    temp_n = n;
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n % 3 == n % 3;
        loop assigns temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 3) {
        //@ assert temp_n >= 3;
        temp_n -= 3;
    }
    if (temp_n == 0) {
        is_divisible_by_3 = true;
    }

    // Check divisibility by 5
    is_divisible_by_5 = false;
    temp_n = n;
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n % 5 == n % 5;
        loop assigns temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 5) {
        //@ assert temp_n >= 5;
        temp_n -= 5;
    }
    if (temp_n == 0) {
        is_divisible_by_5 = true;
    }

    if (is_divisible_by_3 || is_divisible_by_5) {
        return true;
    } else {
        return false;
    }
}
