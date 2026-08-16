#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate c_in_range(integer c) = 1 <= c <= 100;
*/

/*@
    requires a_in_range(a) && b_in_range(b) && c_in_range(c);
    requires a == (int)a && b == (int)b && c == (int)c;
    ensures \result == (b - a == c - b);
*/
bool func(int a, int b, int c)
{
    //@ assert a == (int)a;
    //@ assert b == (int)b;
    //@ assert c == (int)c;
    
    return b - a == c - b;
}
