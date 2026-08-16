#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 0 <= x <= 100;

    logic integer sum(integer a, integer b, integer c) = a + b + c;

    lemma sum_range:
        \forall integer a, b, c;
        valid_range(a) && valid_range(b) && valid_range(c) ==> 
        0 <= sum(a, b, c) <= 300;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == (a + b + c == 180);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    unsigned int total;
    bool result;

    total = a + b + c;
    
    //@ assert 0 <= total <= 300;
    //@ assert total == 180 || total != 180;
    
    result = (total == 180);
    return result;
}
