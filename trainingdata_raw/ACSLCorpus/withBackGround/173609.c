#include <stdbool.h>

/*@
    predicate in_range(integer x) = 1 <= x && x <= 13;

    logic integer sum3(integer a, integer b, integer c) = a + b + c;

    predicate is_special(integer a, integer b, integer c) =
        a == 1 || b == 1 || c == 1 ||
        a == 2 || b == 2 || c == 2 ||
        a == 3 || b == 3 || c == 3;

    lemma sum_range: \forall integer a,b,c;
        in_range(a) && in_range(b) && in_range(c) ==> 3 <= sum3(a,b,c) <= 39;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == true <==> (sum3(a,b,c) < 22 || is_special(a,b,c));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int total;
    bool result;

    //@ assert in_range(a) && in_range(b) && in_range(c);
    total = a + b + c;

    if (total >= 22)
    {
        if (a == 1 || b == 1 || c == 1 || 
            a == 2 || b == 2 || c == 2 || 
            a == 3 || b == 3 || c == 3)
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }
    else
    {
        //@ assert total < 22 || is_special(a,b,c);
        result = true;
    }

    return result;
}
