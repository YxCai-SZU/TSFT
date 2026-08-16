#include <stdint.h>

/*@ predicate in_range(integer x) = 1 <= x <= 10000; */

/*@ lemma product_in_range:
      \forall integer a, b; in_range(a) && in_range(b) ==> a * b <= 100000000; */

/*@
  requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
  ensures \result == a * b || \result == c * d;
  ensures \result >= a * b && \result >= c * d;
  assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d) {
    int64_t res;
    
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert in_range(d);
    
    //@ assert a * b <= 100000000;
    //@ assert c * d <= 100000000;
    
    if (a * b < c * d) {
        res = c * d;
    } else {
        res = a * b;
    }
    
    //@ assert res == a * b || res == c * d;
    //@ assert res >= a * b && res >= c * d;
    
    return res;
}
