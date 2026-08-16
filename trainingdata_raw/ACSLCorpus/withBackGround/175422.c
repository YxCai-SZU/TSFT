#include <stdbool.h>

/*@
    predicate in_range(integer x) = -100 <= x <= 100;

    lemma bounds_lemma:
        \forall integer a, b;
            in_range(a) && in_range(b) ==> (a <= b <==> a <= b);
*/

/*@
    requires in_range(a) && in_range(b);
    ensures \result == (a <= b);
    assigns \nothing;
*/
bool func(int a, int b)
{
    bool result;
    
    //@ assert in_range(a);
    //@ assert in_range(b);
    
    result = (a <= b);
    
    //@ assert result == (a <= b);
    return result;
}
