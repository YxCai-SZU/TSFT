/*@
    predicate in_range(integer v) = -2147483648 <= v <= 2147483647;

    lemma range_lemma:
        \forall integer a, b, c;
        in_range(a) && in_range(b) && in_range(c) && a <= b ==>
        (a <= c && c <= b) == (a <= c && c <= b);
*/

#include <stdbool.h>

/*@
    requires -2147483648 <= a <= 2147483647;
    requires -2147483648 <= b <= 2147483647;
    requires -2147483648 <= c <= 2147483647;
    requires a <= b;
    ensures \result == (a <= c && c <= b);
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert a <= b;
    //@ assert -2147483648 <= a <= 2147483647;
    //@ assert -2147483648 <= b <= 2147483647;
    //@ assert -2147483648 <= c <= 2147483647;

    result = (a <= c) && (c <= b);
    return result;
}
