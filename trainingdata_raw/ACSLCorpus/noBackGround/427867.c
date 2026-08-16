#include <limits.h>

/*@
    requires (1 <= (a) <= 10);
    requires (1 <= (b) <= 10);
    requires (1 <= (c) <= 10);
    requires (1 <= (d) <= 10);
    ensures \result == a + c || \result == a + d || 
            \result == b + c || \result == b + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_cd;
    int result;

    //@ assert (1 <= (a) <= 10);
    //@ assert (1 <= (b) <= 10);
    //@ assert (1 <= (c) <= 10);
    //@ assert (1 <= (d) <= 10);

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

    //@ assert max_ab == (((a) > (b)) ? (a) : (b));
    //@ assert max_cd == (((c) > (d)) ? (c) : (d));
    //@ assert (1 <= (max_ab) <= 10);
    //@ assert (1 <= (max_cd) <= 10);
    //@ assert 2 <= max_ab + max_cd <= 20;

    result = max_ab + max_cd;

    //@ assert result == a + c || result == a + d || result == b + c || result == b + d;

    return result;
}
