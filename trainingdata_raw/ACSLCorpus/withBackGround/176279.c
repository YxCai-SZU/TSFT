#include <limits.h>

/*@
    predicate valid_input(integer x, integer y) =
        1 <= x <= 100 &&
        1 <= y <= 100 &&
        y % 2 == 0;

    logic integer manual_div2(integer n) = n / 2;

    logic integer min(integer a, integer b) = (a < b) ? a : b;

    lemma div2_preserves_even:
        \forall integer y; y % 2 == 0 ==> manual_div2(y) * 2 == y;
*/

/*@
    requires valid_input(x, y);
    ensures \result >= 0;
    ensures \result <= x;
    ensures \result <= (y / 2) * 2;
    assigns \nothing;
*/
int func(int x, int y) {
    int ans = 0;
    int temp_x = x;
    int temp_y = y;
    int quotient = 0;
    int remainder = y;
    int divisor = 2;

    // First division loop
    /*@
        loop invariant 1 <= x <= 100;
        loop invariant 1 <= y <= 100;
        loop invariant y % 2 == 0;
        loop invariant 0 <= quotient <= y / 2;
        loop invariant remainder == y - quotient * 2;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        remainder -= divisor;
        quotient += 1;
    }
    temp_y = quotient * 2;

    // Second division loop
    quotient = 0;
    remainder = temp_y;
    /*@
        loop invariant 1 <= x <= 100;
        loop invariant 1 <= y <= 100;
        loop invariant y % 2 == 0;
        loop invariant 0 <= quotient <= temp_y / 2;
        loop invariant remainder == temp_y - quotient * 2;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        remainder -= divisor;
        quotient += 1;
    }
    temp_y = quotient * 2;

    // Min calculation
    if (temp_x < temp_y) {
        ans = temp_x;
    } else {
        ans = temp_y;
    }

    // Third division loop
    quotient = 0;
    remainder = ans;
    /*@
        loop invariant 1 <= x <= 100;
        loop invariant 1 <= y <= 100;
        loop invariant y % 2 == 0;
        loop invariant 0 <= quotient <= ans / 2;
        loop invariant remainder == ans - quotient * 2;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        remainder -= divisor;
        quotient += 1;
    }
    ans = quotient * 2;

    // Final verification
    //@ assert ans >= 0;
    //@ assert ans <= x;
    //@ assert ans <= (y / 2) * 2;
    
    return ans;
}

int main() {
    return 0;
}
