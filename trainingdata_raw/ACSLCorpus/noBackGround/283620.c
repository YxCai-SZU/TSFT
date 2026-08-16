#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
*/
bool func(long a, long b) {
    bool is_a_multiple_of_3 = false;
    bool is_b_multiple_of_3 = false;
    bool is_a_plus_b_multiple_of_3 = false;
    long temp_a;
    long temp_b;
    long temp_a_plus_b;

    // Check if `a` is a multiple of 3
    temp_a = a;
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant temp_a >= 0;
        loop invariant temp_a <= a;
        loop invariant 1 <= b <= 100;
        loop invariant temp_a % 3 == a % 3;
        loop assigns temp_a;
        loop variant temp_a;
    */
    while (temp_a >= 3) {
        temp_a -= 3;
    }
    if (temp_a == 0) {
        is_a_multiple_of_3 = true;
    }

    // Check if `b` is a multiple of 3
    temp_b = b;
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant temp_b >= 0;
        loop invariant temp_b <= b;
        loop invariant 1 <= b <= 100;
        loop invariant temp_b % 3 == b % 3;
        loop assigns temp_b;
        loop variant temp_b;
    */
    while (temp_b >= 3) {
        temp_b -= 3;
    }
    if (temp_b == 0) {
        is_b_multiple_of_3 = true;
    }

    // Check if `a + b` is a multiple of 3
    temp_a_plus_b = a + b;
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 2 <= a + b <= 200;
        loop invariant temp_a_plus_b >= 0;
        loop invariant temp_a_plus_b <= a + b;
        loop invariant temp_a_plus_b % 3 == (a + b) % 3;
        loop assigns temp_a_plus_b;
        loop variant temp_a_plus_b;
    */
    while (temp_a_plus_b >= 3) {
        temp_a_plus_b -= 3;
    }
    if (temp_a_plus_b == 0) {
        is_a_plus_b_multiple_of_3 = true;
    }

    //@ assert is_a_multiple_of_3 == (a % 3 == 0);
    //@ assert is_b_multiple_of_3 == (b % 3 == 0);
    //@ assert is_a_plus_b_multiple_of_3 == ((a + b) % 3 == 0);

    return is_a_multiple_of_3 || is_b_multiple_of_3 || is_a_plus_b_multiple_of_3;
}
