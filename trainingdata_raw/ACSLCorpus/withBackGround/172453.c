#include <stdbool.h>

/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;

    logic integer safe_product(integer t, integer s) = t * s;

    lemma product_bound: \forall integer t, s;
        valid_params(10000, t, s) ==> t * s <= 10000 * 10000;
*/

/*@
    requires valid_params(d, t, s);
    ensures \result == true <==> d <= t * s;
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    int dist;
    int tim;
    int spe;
    int p;
    bool result;

    dist = d;
    tim = t;
    spe = s;

    //@ assert t <= 10000;
    //@ assert s <= 10000;
    //@ assert t * s <= 10000 * 10000;

    p = tim * spe;
    
    if (p < dist) {
        result = false;
    } else {
        result = true;
    }
    
    return result;
}
