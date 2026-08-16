#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (x / 200 * 200 <= x);
    assigns \nothing;
*/
bool func(int x) {
    int n = 0;
    int temp_x = x;
    
    /*@
        loop invariant 1 <= x <= 100000;
        loop invariant 0 <= temp_x <= x;
        loop invariant n >= 0;
        loop invariant temp_x == ((x) - 200 * (n));
        loop assigns temp_x, n;
        loop variant temp_x;
    */
    while (temp_x >= 200) {
        temp_x -= 200;
        n += 1;
    }
    
    //@ assert n * 200 <= x;
    return n * 200 <= x;
}
