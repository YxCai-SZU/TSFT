#include <limits.h>

/*@ predicate nonnegative(integer x) = x >= 0; */
/*@ predicate product_in_range(integer l, integer w) = 
      l * w <= INT_MAX; */

/*@ requires length >= 0 && width >= 0;
    requires length * width <= INT_MAX;
    ensures \result == length * width;
    assigns \nothing;
 */
int rectangle_area(int length, int width) {
    //@ assert nonnegative(length);
    //@ assert nonnegative(width);
    //@ assert product_in_range(length, width);
    return length * width;
}
