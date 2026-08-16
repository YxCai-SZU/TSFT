#include <limits.h>

/*@
    predicate in_range(integer v) = -10000 <= v <= 10000;
    predicate ordered(integer x, integer y) = x <= y;
*/

/*@
    logic integer product(integer x, integer y) = x * y;
*/

/*@
    lemma product_in_range:
        \forall integer x, integer y;
            in_range(x) && in_range(y) ==> -100000000 <= product(x, y) <= 100000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    requires ordered(a, b) && ordered(c, d);
    ensures \result == product(b, d) || \result == product(a, d) || 
            \result == product(b, c) || \result == product(a, c);
*/
int func(int a, int b, int c, int d)
{
    int ac;
    int ad;
    int bc;
    int bd;
    int max_val;

    //@ assert in_range(a) && in_range(b) && in_range(c) && in_range(d);
    //@ assert ordered(a, b) && ordered(c, d);
    
    ac = a * c;
    ad = a * d;
    bc = b * c;
    bd = b * d;
    
    //@ assert -100000000 <= ac <= 100000000;
    //@ assert -100000000 <= ad <= 100000000;
    //@ assert -100000000 <= bc <= 100000000;
    //@ assert -100000000 <= bd <= 100000000;
    
    if (ac > ad) {
        if (ac > bd) {
            if (ac > bc) {
                max_val = ac;
            } else {
                max_val = bc;
            }
        } else {
            if (bd > bc) {
                max_val = bd;
            } else {
                max_val = bc;
            }
        }
    } else {
        if (ad > bd) {
            if (ad > bc) {
                max_val = ad;
            } else {
                max_val = bc;
            }
        } else {
            if (bd > bc) {
                max_val = bd;
            } else {
                max_val = bc;
            }
        }
    }
    
    //@ assert max_val == product(b, d) || max_val == product(a, d) || max_val == product(b, c) || max_val == product(a, c);
    return max_val;
}
