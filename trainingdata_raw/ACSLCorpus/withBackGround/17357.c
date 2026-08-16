#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    predicate condition(integer a, integer b, integer c, integer d) =
        a > b || b > c || c > d;

    lemma range_lemma:
        \forall integer a, b, c, d;
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==>
        (condition(a,b,c,d) <==> (a > b || b > c || c > d));
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == true <==> condition(a,b,c,d);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c, unsigned long long d)
{
    bool result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);
    
    if (a > b || b > c || c > d) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == true <==> condition(a,b,c,d);
    return result;
}
