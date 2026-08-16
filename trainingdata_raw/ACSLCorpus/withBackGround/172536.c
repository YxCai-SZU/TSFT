#include <stdbool.h>

/*@ predicate is_in_range(integer n, integer m) =
      1 <= n <= 100 && 0 <= m <= n;
*/

/*@ lemma equality_lemma:
      \forall integer n, m;
      is_in_range(n, m) ==> (n == m) == (n == m);
*/

/*@
  requires is_in_range(n, m);
  ensures \result == (n == m);
  assigns \nothing;
*/
bool func(int n, int m) {
    bool s = false;
    
    //@ assert is_in_range(n, m);
    
    if (n == m) {
        s = true;
    } else {
        s = false;
    }
    
    //@ assert s == (n == m);
    
    return s;
}
