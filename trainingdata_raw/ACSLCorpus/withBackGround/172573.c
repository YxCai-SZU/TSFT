#include <limits.h>

/*@ predicate is_valid_range(integer a, integer b, integer c) =
      a > INT_MIN && b > INT_MIN && c > INT_MIN &&
      a < INT_MAX && b < INT_MAX && c < INT_MAX;
*/

/*@ lemma range_lemma:
      \forall integer a, b, c;
        is_valid_range(a, b, c) ==>
        a > INT_MIN && b > INT_MIN && c > INT_MIN &&
        a < INT_MAX && b < INT_MAX && c < INT_MAX;
*/

/*@
  requires is_valid_range(a, b, c);
  ensures \result == (a < b && b < c);
  assigns \nothing;
*/
int func(int a, int b, int c) {
    //@ assert a > INT_MIN;
    //@ assert b > INT_MIN;
    //@ assert c > INT_MIN;
    //@ assert a < INT_MAX;
    //@ assert b < INT_MAX;
    //@ assert c < INT_MAX;
    
    return (a < b) && (b < c);
}
