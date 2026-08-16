#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b) {
    bool a_is_odd = false;
    bool b_is_odd = false;
    unsigned int temp_a = a;
    unsigned int temp_b = b;

    // Check if a is odd
    /*@
        loop invariant 0 <= temp_a <= a;
        loop invariant temp_a % 2 == a % 2;
        loop assigns temp_a;
        loop variant temp_a;
    */
    while (temp_a > 1) {
        temp_a -= 2;
    }
    //@ assert temp_a == 0 || temp_a == 1;
    if (temp_a == 1) {
        a_is_odd = true;
    }

    // Check if b is odd
    /*@
        loop invariant 0 <= temp_b <= b;
        loop invariant temp_b % 2 == b % 2;
        loop assigns temp_b;
        loop variant temp_b;
    */
    while (temp_b > 1) {
        temp_b -= 2;
    }
    //@ assert temp_b == 0 || temp_b == 1;
    if (temp_b == 1) {
        b_is_odd = true;
    }

    if (a_is_odd) {
        if (b_is_odd) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (b_is_odd) {
            return 0;
        } else {
            return 1;
        }
    }
}
