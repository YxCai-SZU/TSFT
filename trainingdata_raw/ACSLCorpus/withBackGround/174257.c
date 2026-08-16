#include <stdbool.h>

/*@ predicate is_valid_params(integer n, integer a, integer b) =
      1 <= n && n <= 20 &&
      1 <= a && a <= 50 &&
      1 <= b && b <= 50;
*/

/*@ logic integer product(integer n, integer a) = n * a; */

/*@ lemma product_bound: 
      \forall integer n, integer a; 
      1 <= n <= 20 && 1 <= a <= 50 ==> product(n, a) <= 1000;
*/

/*@
  requires is_valid_params(n, a, b);
  ensures \result == product(n, a) || \result == b;
  ensures \result <= b;
  assigns \nothing;
*/
int func(int n, int a, int b) {
    // Variable declarations at top of scope
    int prod;
    int res;
    
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert 1 <= b && b <= 50;
    
    //@ assert product(n, a) <= 1000;
    
    prod = n * a;
    
    if (prod < b) {
        res = prod;
    } else {
        res = b;
    }
    
    //@ assert res == product(n, a) || res == b;
    //@ assert res <= b;
    
    return res;
}
