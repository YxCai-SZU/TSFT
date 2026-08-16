#include <stdbool.h>

/*@
    requires 1 <= x <= 100000;
    ensures \result == (x >= 2000 || x % 200 == 0);
    assigns \nothing;
*/
bool func(int x) {
    int n = 0;
    int temp_x = x;
    bool is_divisible = false;

    //@ ghost int original_x = x;

    /*@
        loop invariant 1 <= original_x <= 100000;
        loop invariant 0 <= temp_x <= original_x;
        loop invariant n >= 0;
        loop invariant temp_x == original_x - 200 * n;
        loop assigns temp_x, n;
        loop variant temp_x;
    */
    while (temp_x >= 200) {
        //@ assert temp_x >= 200;
        temp_x -= 200;
        n += 1;
    }

    //@ assert temp_x == original_x - 200 * n;
    //@ assert temp_x == original_x % 200;

    if (temp_x == 0) {
        is_divisible = true;
    }

    //@ assert is_divisible == (original_x % 200 == 0);
    //@ assert x >= 2000 || is_divisible == (x >= 2000 || original_x % 200 == 0);
    return x >= 2000 || is_divisible;
}
