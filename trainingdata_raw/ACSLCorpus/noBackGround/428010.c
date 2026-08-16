#include <limits.h>

/*@
    requires (1 <= (a) <= 10000 &&
        1 <= (b) <= 10000 &&
        (a) * (b) <= 1000000000);
    ensures \result == (((a) * (b)) % 2 != 0);
*/
int func(int a, int b) {
    int product;
    int is_odd = 0;
    int abs_product;
    int remainder;

    //@ assert (1 <= (a) <= 10000 &&         1 <= (b) <= 10000 &&         (a) * (b) <= 1000000000);
    //@ assert INT_MIN <= a * b <= INT_MAX;

    product = a * b;

    //@ assert product == a * b;

    if (product < 0) {
        abs_product = -product;
    } else {
        abs_product = product;
    }

    //@ assert abs_product == ((product) >= 0 ? (product) : -(product));

    remainder = abs_product;

    /*@
        loop invariant 0 <= remainder <= abs_product;
        loop invariant remainder % 2 == abs_product % 2;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2) {
        remainder -= 2;
    }

    //@ assert remainder == abs_product % 2;

    if (remainder == 1) {
        is_odd = 1;
    }

    //@ assert is_odd == (product % 2 != 0);
    return is_odd;
}
