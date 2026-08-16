#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x && x <= 100;

    logic integer sum(integer x, integer y) = x + y;

    predicate is_triangle_sum(integer a, integer b, integer c) =
        sum(a, b) == c || sum(a, c) == b || sum(b, c) == a;

    lemma sum_bounds_ab:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> 2 <= sum(a, b) && sum(a, b) <= 200;

    lemma sum_bounds_ac:
        \forall integer a, c;
        valid_range(a) && valid_range(c) ==> 2 <= sum(a, c) && sum(a, c) <= 200;

    lemma sum_bounds_bc:
        \forall integer b, c;
        valid_range(b) && valid_range(c) ==> 2 <= sum(b, c) && sum(b, c) <= 200;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == true <==> is_triangle_sum(a, b, c);
    assigns \nothing;
*/
bool func(long a, long b, long c)
{
    //@ assert valid_range(a) && valid_range(b) && valid_range(c);
    
    //@ assert 2 <= a + b && a + b <= 200;
    //@ assert 2 <= a + c && a + c <= 200;
    //@ assert 2 <= b + c && b + c <= 200;
    
    if (a + b == c || a + c == b || b + c == a)
    {
        return true;
    }
    else
    {
        return false;
    }
}
