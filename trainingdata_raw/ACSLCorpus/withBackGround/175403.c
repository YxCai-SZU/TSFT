#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    lemma multiplication_bound:
        \forall integer t, s;
            valid_range(t) && valid_range(s) ==> t * s <= 10000 * 10000;
*/

/*@
    requires valid_range(d) && valid_range(t) && valid_range(s);
    ensures \result == (t * s >= d);
    assigns \nothing;
*/
bool func(unsigned int d, unsigned int t, unsigned int s)
{
    // Variable declarations at top of scope
    unsigned int product;
    bool result;
    
    //@ assert valid_range(t);
    //@ assert valid_range(s);
    //@ assert t * s <= 10000 * 10000;
    
    product = t * s;
    result = (product >= d);
    
    //@ assert result == (t * s >= d);
    return result;
}

int main()
{
    // main function body
    return 0;
}
