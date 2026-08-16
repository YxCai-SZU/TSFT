#include <stdbool.h>

/*@
    predicate is_valid_range(integer r) = 1 <= r && r <= 100;
    logic integer calculate_result(integer r) = 2 * r * 314 / 100;
    logic integer calculate_raw(integer r) = r * 2 * 314;
*/

/*@
    requires is_valid_range(r);
    ensures \result == calculate_result(r);
*/
int func(int r) {
    int pi = 314;
    int result = r * 2 * pi;
    int divisor = 100;
    int quotient = 0;
    int remainder = result;

    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= result / divisor;
        loop invariant remainder == result - quotient * divisor;
        loop invariant quotient * 100 + remainder == result;
        loop invariant divisor == 100;
        loop invariant pi == 314;
        loop invariant result == r * 2 * pi;
        loop invariant 1 <= r && r <= 100;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        quotient += 1;
        remainder -= divisor;
    }

    //@ assert quotient * 100 + remainder == result;
    //@ assert quotient == 2 * r * 314 / 100;

    return quotient;
}

int main() {
    return 0;
}
