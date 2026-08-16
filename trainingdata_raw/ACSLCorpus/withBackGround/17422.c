#include <stdbool.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 20 &&
        1 <= c && c <= 2000;

    lemma product_bound: \forall integer a, b;
        valid_input(a, b, 2000) ==> a * b <= 2000;
*/

/*@
    requires valid_input(a, b, c);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == a * b || \result == c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at scope top
    int x;
    int result;

    //@ assert valid_input(a, b, c);
    //@ assert a * b <= 2000;

    x = a * b;
    
    if (x < c)
    {
        result = x;
    }
    else
    {
        result = c;
    }

    //@ assert result >= 0;
    //@ assert result <= c;
    //@ assert result == a * b || result == c;
    
    return result;
}
