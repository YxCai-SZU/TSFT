#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer sum(integer x, integer y) = x + y;

    lemma sum_gt_implies_true:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            (sum(a, c) > b ==> a + c > b);

    lemma sum_le_implies_false:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            (sum(a, c) <= b ==> !(a + c > b));
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == true <==> a + c > b;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    bool result;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    
    if (a + c > b)
    {
        //@ assert a + c > b;
        result = true;
    }
    else
    {
        //@ assert !(a + c > b);
        result = false;
    }

    //@ assert result == true <==> a + c > b;
    return result;
}
