#include <limits.h>
#include <stdbool.h>

/*@ predicate is_lt(integer a, integer b, integer c) = a < b && b < c; */

/*@ lemma transitivity: \forall integer a, b, c; 
      a > INT_MIN && b > INT_MIN && c > INT_MIN &&
      a < INT_MAX && b < INT_MAX && c < INT_MAX &&
      a < b && b < c ==> a < c; */

/*@ requires a > INT_MIN && b > INT_MIN && c > INT_MIN;
    requires a < INT_MAX && b < INT_MAX && c < INT_MAX;
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(int a, int b, int c) {
    //@ assert a > INT_MIN && b > INT_MIN && c > INT_MIN;
    //@ assert a < INT_MAX && b < INT_MAX && c < INT_MAX;
    //@ assert a <= INT_MAX && b <= INT_MAX && c <= INT_MAX;
    //@ assert a >= INT_MIN && b >= INT_MIN && c >= INT_MIN;
    //@ assert a < b && b < c ==> a < c;
    return a < b && b < c;
}
