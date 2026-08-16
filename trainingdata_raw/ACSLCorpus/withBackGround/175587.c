#include <stdbool.h>

/*@ predicate in_range(integer x) = 1 <= x <= 10; */

/*@ lemma product_range:
      \forall integer a, integer c;
        in_range(a) && in_range(c) ==> 1 <= a * c <= 100; */

/*@ requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == (a * c <= 5 && b * d <= 5);
    assigns \nothing;
 */
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    // Variable declarations at scope top
    bool result;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert in_range(d);

    //@ assert 1 <= a * c <= 100;
    //@ assert 1 <= b * d <= 100;

    result = (a * c <= 5) && (b * d <= 5);
    return result;
}
