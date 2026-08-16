#include <stdbool.h>

/*@ requires
        (1 <= (d) && (d) <= 10000 &&
        1 <= (t) && (t) <= 10000 &&
        1 <= (s) && (s) <= 10000);
    ensures
        \result == (t * s >= d);
*/
bool func(unsigned int d, unsigned int t, unsigned int s)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int product_val;

    //@ assert 1 <= t && t <= 10000;
    //@ assert 1 <= s && s <= 10000;
    //@ assert t * s <= 100000000;

    product_val = t * s;
    result = (product_val >= d);
    return result;
}
