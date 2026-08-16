#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b, integer c) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 20 &&
        1 <= c && c <= 2000;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bounds:
        \forall integer a, b;
        1 <= a && a <= 100 && 1 <= b && b <= 20 ==> 1 <= product(a, b) <= 2000;
*/

/*@
    requires valid_range(a, b, c);
    ensures \result <= c;
    ensures \result == a * b || \result == c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at top of scope
    int result;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 20;
    //@ assert 1 <= c && c <= 2000;
    
    //@ assert 1 <= a * b && a * b <= 2000;
    
    if (a * b < c) {
        result = a * b;
        //@ assert result == a * b;
        //@ assert result < c;
    } else {
        //@ assert a * b >= c;
        result = c;
        //@ assert result == c;
    }
    
    //@ assert result <= c;
    //@ assert result == a * b || result == c;
    
    return result;
}
