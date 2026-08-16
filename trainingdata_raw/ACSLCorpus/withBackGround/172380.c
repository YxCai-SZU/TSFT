#include <stdbool.h>

/*@ predicate can_distribute(integer a, integer b, integer c) =
      a + b == c || a + c == b || b + c == a;
*/

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  ensures \result == true <==> can_distribute(a, b, c);
*/
bool can_distribute_equally(int a, int b, int c) {
    bool result;
    //@ assert can_distribute(a, b, c) <==> (a + b == c || a + c == b || b + c == a);
    result = (a + b == c) || (a + c == b) || (b + c == a);
    //@ assert result == true <==> can_distribute(a, b, c);
    return result;
}
