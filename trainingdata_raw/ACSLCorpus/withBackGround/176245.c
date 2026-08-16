#include <limits.h>

/*@
    predicate valid_range(integer x) = -100 <= x <= 100;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
    ensures \result >= a + c;
    ensures \result >= a + d;
    ensures \result >= b + c;
    ensures \result >= b + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_cd;
    int res;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    
    if (a > b) {
        max_ab = a;
    } else {
        max_ab = b;
    }
    
    if (c > d) {
        max_cd = c;
    } else {
        max_cd = d;
    }
    
    res = max_ab + max_cd;
    
    //@ assert res == a + c || res == a + d || res == b + c || res == b + d;
    //@ assert res >= a + c;
    //@ assert res >= a + d;
    //@ assert res >= b + c;
    //@ assert res >= b + d;
    
    return res;
}
