#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    lemma product_bounds:
        \forall integer t, s; valid_range(t) && valid_range(s) ==> 1 <= t * s <= 100000000;
*/

/*@
    requires valid_range(d) && valid_range(t) && valid_range(s);
    ensures \result == (t * s >= d);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    bool result = false;
    int i = 0;

    /*@
        loop invariant 0 <= i <= 2;
        loop invariant valid_range(d) && valid_range(t) && valid_range(s);
        loop invariant i > 0 ==> result == (t * s >= d);
        loop invariant i == 0 ==> result == false;
        loop assigns i, result;
        loop variant 2 - i;
    */
    while (i < 2)
    {
        //@ assert 1 <= t * s <= 100000000;
        
        if (t * s >= d) {
            result = true;
        } else {
            result = false;
        }
        i += 1;
    }
    
    //@ assert result == (t * s >= d);
    return result;
}
