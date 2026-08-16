#include <stdint.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == (((l) / 3) * ((l) / 3) * ((l) / 3));
    assigns \nothing;
*/
int64_t func(int64_t l) {
    // Variable declarations at top of scope
    uint64_t l_unsigned;
    uint64_t quotient = 0;
    uint64_t remainder;
    uint64_t divisor = 3;
    int64_t l_div_3;
    int64_t result;

    // Convert l to unsigned for manual division
    if (l < 0) {
        l_unsigned = (uint64_t)(-l);
    } else {
        l_unsigned = (uint64_t)l;
    }
    remainder = l_unsigned;

    // Manual division loop
    /*@
        loop invariant 0 <= quotient <= l_unsigned / divisor;
        loop invariant remainder == l_unsigned - quotient * divisor;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        quotient = quotient + 1;
        remainder = remainder - divisor;
    }

    // Convert quotient back to signed
    if (l < 0) {
        l_div_3 = -(int64_t)quotient;
    } else {
        l_div_3 = (int64_t)quotient;
    }

    // Critical verification properties
    //@ assert l_div_3 >= 0 && l_div_3 <= 333;
    //@ assert l_div_3 * l_div_3 <= 333 * 333;
    //@ assert l_div_3 * l_div_3 * l_div_3 <= 333 * 333 * 333;

    result = l_div_3 * l_div_3 * l_div_3;
    //@ assert result == (((l) / 3) * ((l) / 3) * ((l) / 3));
    return result;
}

int main() {
    return 0;
}
