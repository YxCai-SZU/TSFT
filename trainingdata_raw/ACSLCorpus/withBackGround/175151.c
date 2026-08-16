/*@
    predicate in_range(integer x) = 1 <= x && x <= 100;

    lemma abc_helper:
        \forall integer a, b, c;
        in_range(a) && in_range(b) && in_range(c) ==>
        a <= 100 && b <= 100 && c <= 100;
*/

#include <stdbool.h>

/*@
    requires in_range(a);
    requires in_range(b);
    requires in_range(c);
    ensures \result == (a <= c && c <= b);
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top
    bool abc;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);

    abc = (a <= c) && (c <= b);

    //@ assert abc == (a <= c && c <= b);

    return abc;
}
