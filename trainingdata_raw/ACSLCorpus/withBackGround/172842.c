#include <limits.h>

/*@
    predicate is_minimum(integer ret, integer a, integer b) =
        (ret == a || ret == b) &&
        ret <= a &&
        ret <= b;
*/

/*@
    lemma min_proof:
        \forall integer a, b;
            (a < b ==> a <= a && a <= b) &&
            (!(a < b) ==> b <= a && b <= b);
*/

/*@
    requires \true;
    ensures is_minimum(\result, a, b);
*/
int minimum(int a, int b)
{
    int ret;
    
    //@ assert \true;
    
    if (a < b)
    {
        ret = a;
    }
    else
    {
        ret = b;
    }
    
    //@ assert is_minimum(ret, a, b);
    return ret;
}
