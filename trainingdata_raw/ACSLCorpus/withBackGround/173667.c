#include <limits.h>

/*@ predicate in_range(integer v) = -1000 <= v <= 1000; */

/*@ logic integer product(integer x, integer y) = x * y; */

/*@ lemma product_in_range: 
      \forall integer a, integer b; 
        in_range(a) && in_range(b) ==> 
        -1000000 <= product(a, b) <= 1000000; */

/*@ requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == product(a, c) || 
            \result == product(a, d) || 
            \result == product(b, c) || 
            \result == product(b, d);
    assigns \nothing;
 */
int func(int a, int b, int c, int d)
{
    int x;
    int y;
    int z;
    int w;
    int max1;
    int max2;
    int max_value;

    //@ assert -1000000 <= product(a, c) <= 1000000;
    //@ assert -1000000 <= product(b, d) <= 1000000;
    //@ assert -1000000 <= product(a, d) <= 1000000;
    //@ assert -1000000 <= product(b, c) <= 1000000;

    x = a * c;
    y = b * d;
    z = a * d;
    w = b * c;

    if (x > y) {
        max1 = x;
    } else {
        max1 = y;
    }

    if (z > w) {
        max2 = z;
    } else {
        max2 = w;
    }

    if (max1 > max2) {
        max_value = max1;
    } else {
        max_value = max2;
    }

    //@ assert max_value == product(a, c) || max_value == product(a, d) || max_value == product(b, c) || max_value == product(b, d);
    return max_value;
}
