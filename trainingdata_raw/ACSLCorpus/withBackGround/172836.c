#include <stdbool.h>

/*@
    predicate diff_in_range(integer a, integer b) =
        a >= 1 && a <= 100 && b >= 1 && b <= 100 &&
        b - a >= -2147483648 && b - a <= 2147483647;
*/

/*@
    lemma diff_preserved:
        \forall integer a, b, c, d;
            diff_in_range(a, b) && diff_in_range(c, d) ==>
            (b - a == d - c) == ((b - a) == (d - c));
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == (b - a == d - c);
*/
bool func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert diff_in_range(a, b);
    //@ assert diff_in_range(c, d);
    
    result = (b - a == d - c);
    return result;
}
