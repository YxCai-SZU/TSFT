#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate x_in_range(integer x) = 1 <= x <= 200;
    
    lemma condition_lemma:
        \forall integer a, b, x;
        a_in_range(a) && b_in_range(b) && x_in_range(x) ==>
        (a <= x && a + b >= x) ==> (a <= x && a + b >= x);
*/

/*@
    requires a_in_range(a) && b_in_range(b) && x_in_range(x);
    ensures \result == (a <= x && a + b >= x);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    // Variable declarations at top of scope
    bool result;
    
    if (a > x)
    {
        //@ assert a > x;
        result = false;
        return result;
    }
    
    if (a + b < x)
    {
        //@ assert a + b < x;
        result = false;
        return result;
    }
    
    //@ assert a <= x && a + b >= x;
    result = true;
    return result;
}
