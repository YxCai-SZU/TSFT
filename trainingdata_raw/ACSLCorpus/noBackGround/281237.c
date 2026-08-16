#include <limits.h>

/*@
    requires (-100 <= (a) <= 100 && -100 <= (b) <= 100 &&
        -100 <= (c) <= 100 && -100 <= (d) <= 100);
    ensures \result == a || \result == b || \result == c || \result == d ||
            \result == a + b || \result == a + c || \result == a + d ||
            \result == b + c || \result == b + d || \result == c + d ||
            \result == a + b + c || \result == a + b + d ||
            \result == a + c + d || \result == b + c + d ||
            \result == a + b + c + d;
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_cd;
    int max_value;

    //@ assert (-100 <= (a) <= 100 && -100 <= (b) <= 100 &&         -100 <= (c) <= 100 && -100 <= (d) <= 100);

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

    if (max_ab > max_cd) {
        max_value = max_ab;
    } else {
        max_value = max_cd;
    }

    //@ assert max_value == ((((((a)) > ((b)) ? ((a)) : ((b)))) > ((((c)) > ((d)) ? ((c)) : ((d)))) ? ((((a)) > ((b)) ? ((a)) : ((b)))) : ((((c)) > ((d)) ? ((c)) : ((d))))));
    //@ assert max_value == a || max_value == b || max_value == c || max_value == d;

    return max_value;
}
