#include <limits.h>

/*@
    requires (1 <= (X) <= 100) && (1 <= (Y) <= 100) && ((Y) % 2 == 0);
    ensures \result >= 0 && \result <= X;
*/
int func(int X, int Y) {
    int ans = 0;
    int temp_x = X;
    int temp_y = Y;
    int quotient = 0;
    int remainder = temp_y;

    // First division loop (Y/2)
    /*@
        loop invariant 0 <= quotient <= temp_y / 2;
        loop invariant remainder == temp_y - 2 * quotient;
        loop invariant (1 <= (X) <= 100) && (1 <= (Y) <= 100);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 2) {
        remainder -= 2;
        quotient += 1;
    }
    temp_y = quotient;

    // Second division loop (X/2)
    quotient = 0;
    remainder = temp_x;
    /*@
        loop invariant 0 <= quotient <= temp_x / 2;
        loop invariant remainder == temp_x - 2 * quotient;
        loop invariant (1 <= (X) <= 100) && (1 <= (Y) <= 100);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 2) {
        remainder -= 2;
        quotient += 1;
    }
    temp_x = quotient;

    // Main calculation loop
    /*@
        loop invariant 0 <= temp_x <= X;
        loop invariant 0 <= temp_y <= Y;
        loop invariant ans >= 0 && ans <= X;
        loop invariant ans <= X - temp_x;
        loop invariant (1 <= (X) <= 100) && (1 <= (Y) <= 100);
        loop assigns temp_x, ans;
        loop variant temp_x;
    */
    while (temp_x >= temp_y) {
        temp_x -= temp_y;
        ans += 1;
    }

    //@ assert ans <= X;
    return ans;
}
