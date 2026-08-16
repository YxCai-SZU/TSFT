#include <limits.h>

/*@
    predicate in_range(integer x, integer low, integer high) =
        low <= x <= high;

    logic integer compute_res(integer x) =
        (400 <= x <= 599) ? 8 :
        (600 <= x <= 799) ? 7 :
        (800 <= x <= 999) ? 6 :
        (1000 <= x <= 1199) ? 5 :
        (1200 <= x <= 1399) ? 4 :
        (1400 <= x <= 1599) ? 3 :
        (1600 <= x <= 1799) ? 2 :
        (1800 <= x <= 1999) ? 1 : -1;

    lemma res_correctness:
        \forall integer x;
            400 <= x <= 1999 ==>
            compute_res(x) == (
                (400 <= x <= 599) ? 8 :
                (600 <= x <= 799) ? 7 :
                (800 <= x <= 999) ? 6 :
                (1000 <= x <= 1199) ? 5 :
                (1200 <= x <= 1399) ? 4 :
                (1400 <= x <= 1599) ? 3 :
                (1600 <= x <= 1799) ? 2 :
                (1800 <= x <= 1999) ? 1 : -1
            );
*/

/*@
    requires 400 <= x <= 1999;
    ensures \result == compute_res(x);
    ensures (400 <= x && x <= 599 ==> \result == 8) &&
            (600 <= x && x <= 799 ==> \result == 7) &&
            (800 <= x && x <= 999 ==> \result == 6) &&
            (1000 <= x && x <= 1199 ==> \result == 5) &&
            (1200 <= x && x <= 1399 ==> \result == 4) &&
            (1400 <= x && x <= 1599 ==> \result == 3) &&
            (1600 <= x && x <= 1799 ==> \result == 2) &&
            (1800 <= x && x <= 1999 ==> \result == 1);
    assigns \nothing;
*/
int func(int x)
{
    int res;
    //@ assert 400 <= x <= 1999;
    
    if (x >= 400 && x <= 599) {
        res = 8;
    } else if (x >= 600 && x <= 799) {
        res = 7;
    } else if (x >= 800 && x <= 999) {
        res = 6;
    } else if (x >= 1000 && x <= 1199) {
        res = 5;
    } else if (x >= 1200 && x <= 1399) {
        res = 4;
    } else if (x >= 1400 && x <= 1599) {
        res = 3;
    } else if (x >= 1600 && x <= 1799) {
        res = 2;
    } else if (x >= 1800 && x <= 1999) {
        res = 1;
    } else {
        res = -1;
    }
    
    //@ assert res == compute_res(x);
    return res;
}
