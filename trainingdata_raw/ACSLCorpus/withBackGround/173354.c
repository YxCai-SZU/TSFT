#include <limits.h>

/*@
    predicate non_negative(integer v) = v >= 0;
    predicate no_overflow(integer l, integer w) = 
        l * w <= INT_MAX;
*/

/*@
    requires non_negative(length) && non_negative(width);
    requires no_overflow(length, width);
    ensures \result == length * width;
    ensures non_negative(\result);
*/
int area_rectangle(int length, int width) {
    // Variable declarations at top of scope
    int ret;

    //@ assert non_negative(length) && non_negative(width);
    //@ assert no_overflow(length, width);
    //@ assert length * width >= 0;

    ret = length * width;
    return ret;
}
