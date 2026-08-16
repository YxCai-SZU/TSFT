#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100;

    logic integer condition_holds(integer a, integer b, integer c, integer d) =
        (a - 1 == c && b - 1 == d) ||
        (a - 1 == d && b - 1 == c) ||
        (a == c && b - 1 == d - 1) ||
        (a == d && b - 1 == c - 1) ||
        (a + 1 == c && b - 1 == d - 1) ||
        (a - 1 == c && b == d - 1) ||
        (a == c && b == d - 1) ||
        (a - 1 == d && b == c - 1) ||
        (a == d && b == c - 1) ? 1 : 0;

    lemma range_lemma:
        \forall integer a, b, c, d;
            is_valid_range(a) && is_valid_range(b) &&
            is_valid_range(c) && is_valid_range(d) ==>
            -99 <= a - 1 <= 99 && -99 <= b - 1 <= 99 &&
            -99 <= c - 1 <= 99 && -99 <= d - 1 <= 99;
*/

/*@
    requires is_valid_range(a);
    requires is_valid_range(b);
    requires is_valid_range(c);
    requires is_valid_range(d);
    ensures \result == true <==> condition_holds(a, b, c, d) == 1;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    //@ assert is_valid_range(a);
    bool result;
    
    result = (a - 1 == c && b - 1 == d) ||
             (a - 1 == d && b - 1 == c) ||
             (a == c && b - 1 == d - 1) ||
             (a == d && b - 1 == c - 1) ||
             (a + 1 == c && b - 1 == d - 1) ||
             (a - 1 == c && b == d - 1) ||
             (a == c && b == d - 1) ||
             (a - 1 == d && b == c - 1) ||
             (a == d && b == c - 1);
    
    //@ assert result == true <==> condition_holds(a, b, c, d) == 1;
    return result;
}
