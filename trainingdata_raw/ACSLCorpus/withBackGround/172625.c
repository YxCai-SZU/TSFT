#include <stdbool.h>

/*@
    predicate in_range(integer a, integer b, integer x) =
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= x <= 200;
    
    logic integer sum(integer a, integer b) = a + b;
    
    lemma condition_lemma:
        \forall integer a, b, x;
            in_range(a, b, x) ==>
            (b <= x && x <= sum(a, b)) || !(b <= x && x <= sum(a, b));
*/

/*@
    requires in_range(a, b, x);
    ensures \result == (b <= x && x <= (a + b));
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert in_range(a, b, x);
    
    if (b <= x && x <= (a + b)) {
        //@ assert b <= x && x <= (a + b);
        result = true;
    } else {
        //@ assert !(b <= x && x <= (a + b));
        result = false;
    }
    
    return result;
}
