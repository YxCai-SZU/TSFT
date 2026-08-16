#include <stdint.h>

/*@
    requires (1 <= (x) <= 1000000000);
    ensures \result >= 0;
    ensures \result <= x / 11 * 2 + 2;
*/
int64_t func(int64_t x)
{
    int64_t result = 0;
    int64_t quotient = 0;
    int64_t remainder = x;
    int64_t product = 0;
    int64_t i = 0;

    //@ assert remainder == x;
    //@ assert quotient == 0;

    /*@
        loop invariant 1 <= x <= 1000000000;
        loop invariant 0 <= quotient;
        loop invariant quotient <= x / 11;
        loop invariant remainder == x - quotient * 11;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 11) {
        //@ assert remainder >= 11;
        quotient += 1;
        remainder -= 11;
        //@ assert remainder == x - quotient * 11;
    }

    //@ assert quotient == x / 11;
    //@ assert 0 <= remainder < 11;

    /*@
        loop invariant 1 <= x <= 1000000000;
        loop invariant 0 <= i;
        loop invariant i <= quotient;
        loop invariant product == i * 2;
        loop invariant quotient <= x / 11;
        loop invariant product <= x / 11 * 2;
        loop assigns product, i;
        loop variant quotient - i;
    */
    while (i < quotient) {
        //@ assert i < quotient;
        product += 2;
        i += 1;
        //@ assert product == i * 2;
    }

    //@ assert product == quotient * 2;
    result = product;

    if (remainder > 6) {
        //@ assert remainder > 6;
        result += 2;
        //@ assert result == quotient * 2 + 2;
    } else {
        //@ assert remainder <= 6;
        result += 1;
        //@ assert result == quotient * 2 + 1;
    }

    //@ assert result >= 0;
    //@ assert result <= x / 11 * 2 + 2;
    return result;
}
