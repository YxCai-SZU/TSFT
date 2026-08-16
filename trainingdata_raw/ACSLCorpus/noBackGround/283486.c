#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 10000 &&
        1 <= (b) && (b) <= 10000 &&
        (a) * (b) <= 9223372036854775807 &&
        (a) * (b) >= -9223372036854775808);
    ensures \result == ((a * b) % 2 != 0);
*/
bool func(long a, long b)
{
    long product;
    bool is_odd;
    long abs_product;
    long remainder;

    product = a * b;
    is_odd = false;
    abs_product = product;

    if (product < 0) {
        abs_product = -product;
    }

    remainder = abs_product;
    /*@
        loop invariant remainder >= 0;
        loop invariant remainder <= abs_product;
        loop invariant remainder % 2 == abs_product % 2;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2) {
        remainder -= 2;
    }

    //@ assert remainder == abs_product % 2;

    if (remainder == 1) {
        is_odd = true;
    }

    return is_odd;
}
