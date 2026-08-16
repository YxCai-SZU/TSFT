#include <stdbool.h>

/*@ predicate is_ordered(integer a, integer b, integer c) = 
      a < b && b < c; */

/*@ requires 0 <= a && a <= 100;
    requires 0 <= b && b <= 100;
    requires 0 <= c && c <= 100;
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(int a, int b, int c) {
    //@ assert 0 <= a && a <= 100;
    //@ assert 0 <= b && b <= 100;
    //@ assert 0 <= c && c <= 100;
    return (a < b) && (b < c);
}
