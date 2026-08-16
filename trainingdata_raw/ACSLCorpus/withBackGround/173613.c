#include <stdbool.h>

/*@ predicate can_distribute(integer a, integer b, integer c) =
      a + b == c || b + c == a || c + a == b;
*/

/*@
  requires 1 <= a && a <= 100;
  requires 1 <= b && b <= 100;
  requires 1 <= c && c <= 100;
  ensures \result <==> can_distribute(a, b, c);
*/
bool can_distribute_evenly(int a, int b, int c) {
    bool result;
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    
    if (a + b == c || b + c == a || c + a == b) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result <==> can_distribute(a, b, c);
    return result;
}
