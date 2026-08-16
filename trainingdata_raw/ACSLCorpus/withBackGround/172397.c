#include <stdbool.h>

/*@ predicate is_valid_range(integer n, integer m) =
      1 <= n <= 100 && 0 <= m <= n;
*/

/*@ lemma equality_lemma:
      \forall integer n, m;
      is_valid_range(n, m) ==> (n == m || n != m);
*/

/*@ requires is_valid_range(n, m);
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m) {
    //@ assert n == m || n != m;
    return n == m;
}
