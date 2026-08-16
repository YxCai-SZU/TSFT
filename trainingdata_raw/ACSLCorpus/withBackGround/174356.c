#include <stdbool.h>

/*@ predicate is_arithmetic_sequence(integer a, integer b, integer c) =
      b - a == c - b;
*/

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  ensures \result == (b - a == c - b);
*/
bool func(int a, int b, int c)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert b - a == c - b ==> (b - a == c - b);
    
    result = (b - a == c - b);
    return result;
}
