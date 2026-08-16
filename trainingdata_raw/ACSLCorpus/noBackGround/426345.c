#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= 1;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    // Variable declarations at top of scope
    int64_t product1;
    int64_t product2;
    int64_t max_value;

    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    //@ assert ((a) * (b)) <= 10000 * 10000;
    product1 = a * b;

    //@ assert (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    //@ assert ((c) * (d)) <= 10000 * 10000;
    product2 = c * d;

    //@ assert product1 >= 1;
    //@ assert product2 >= 1;

    if (product1 > product2) {
        max_value = product1;
        //@ assert max_value == ((a) * (b));
    } else {
        max_value = product2;
        //@ assert max_value == ((c) * (d));
    }

    return max_value;
}
