#include <stdbool.h>

/*@ predicate valid_range(integer a, integer b) =
      1 <= a && a <= 100 &&
      1 <= b && b <= 100;
*/

/*@ predicate product_in_range(integer a, integer b, integer result) =
      result == a * b &&
      1 * 1 <= a * b && a * b <= 100 * 100;
*/

/*@ lemma product_bound: \forall integer a, b;
      valid_range(a, b) ==> a * b <= 10000;
*/

/*@ requires valid_range(a, b);
    ensures \result == a * b;
    assigns \nothing;
*/
int func(int a, int b) {
    // Variable declarations at top of scope
    int result;
    
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 * 1 <= a * b && a * b <= 100 * 100;
    //@ assert a * b <= 10000;
    
    result = a * b;
    return result;
}
