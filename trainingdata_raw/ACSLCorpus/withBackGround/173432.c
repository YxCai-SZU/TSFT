#include <stdbool.h>

/*@ predicate can_reach_condition(integer a, integer b, integer c) =
      b - c < a && a < b;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (b - c < a && a < b);
*/
bool can_reach_bstop(int a, int b, int c)
{
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    
    bool result = (b - c < a) && (a < b);
    return result;
}
