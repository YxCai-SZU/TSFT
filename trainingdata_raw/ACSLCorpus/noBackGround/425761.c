#include <limits.h>

/*@
    requires ((x) >= 1 && (x) <= 100 &&
        (y) >= 1 && (y) <= 100 &&
        (y) % 2 == 0);
    ensures \result == x + ((y) / 2);
    assigns \nothing;
*/
int func(int x, int y) {
    int ans;
    int quotient;
    int remainder;
    int abs_y;
    
    ans = x;
    quotient = 0;
    remainder = 0;
    abs_y = (y < 0) ? -y : y;
    
    /*@
        loop invariant 0 <= abs_y;
        loop invariant 0 <= quotient;
        loop invariant abs_y + 2 * quotient == y;
        loop invariant quotient <= ((y) / 2);
        loop invariant abs_y <= y;
        loop assigns abs_y, quotient;
        loop variant abs_y;
    */
    while (abs_y >= 2) {
        abs_y -= 2;
        quotient += 1;
    }
    remainder = abs_y;
    
    if (y < 0) {
        quotient = -quotient;
    }
    
    ans += quotient;
    
    //@ assert ans == x + ((y) / 2);
    
    return ans;
}
