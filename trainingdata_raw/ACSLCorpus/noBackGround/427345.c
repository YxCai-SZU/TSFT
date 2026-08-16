#include <stdbool.h>

/*@ requires (1 <= (x) <= 100) && (1 <= (y) <= 100) && (1 <= (z) <= 100);
    requires ((x) <= (y) <= (z));
    ensures \result == (x <= z);
    assigns \nothing;
*/
bool func(long x, long y, long z) {
    // Variable declarations at scope top
    bool result;

    //@ assert (1 <= (x) <= 100);
    //@ assert (1 <= (y) <= 100);
    //@ assert (1 <= (z) <= 100);
    //@ assert ((x) <= (y) <= (z));
    //@ assert x <= z;

    result = (x <= z);
    return result;
}
