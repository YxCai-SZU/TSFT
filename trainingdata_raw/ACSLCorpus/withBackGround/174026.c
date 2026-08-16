/*@
    logic integer max(integer x, integer y) = (x > y) ? x : y;

    lemma max_ge_x:
        \forall integer x, y; max(x, y) >= x;

    lemma max_ge_y:
        \forall integer x, y; max(x, y) >= y;

    lemma max_is_x_or_y:
        \forall integer x, y; max(x, y) == x || max(x, y) == y;
*/

#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (a + b == c || a + c == b || b + c == a);
*/
bool func(int a, int b, int c)
{
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    
    return (a + b == c) || (a + c == b) || (b + c == a);
}
