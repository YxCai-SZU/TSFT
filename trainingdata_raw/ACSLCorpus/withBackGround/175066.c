#include <limits.h>

/*@
    predicate in_range(integer x, integer low, integer high) =
        low <= x <= high;

    logic integer compute_result(integer x) =
        (400 <= x <= 599) ? 8 :
        (600 <= x <= 799) ? 7 :
        (800 <= x <= 999) ? 6 :
        (1000 <= x <= 1199) ? 5 :
        (1200 <= x <= 1399) ? 4 :
        (1400 <= x <= 1599) ? 3 :
        (1600 <= x <= 1799) ? 2 :
        (1800 <= x <= 1999) ? 1 : -1;

    lemma result_correctness:
        \forall integer x;
            400 <= x <= 1999 ==>
            compute_result(x) ==
                ((400 <= x <= 599) ? 8 :
                (600 <= x <= 799) ? 7 :
                (800 <= x <= 999) ? 6 :
                (1000 <= x <= 1199) ? 5 :
                (1200 <= x <= 1399) ? 4 :
                (1400 <= x <= 1599) ? 3 :
                (1600 <= x <= 1799) ? 2 :
                (1800 <= x <= 1999) ? 1 : -1);
*/

/*@
    requires 400 <= x <= 1999;
    ensures \result == compute_result(x);
    ensures (400 <= x <= 599 ==> \result == 8);
    ensures (600 <= x <= 799 ==> \result == 7);
    ensures (800 <= x <= 999 ==> \result == 6);
    ensures (1000 <= x <= 1199 ==> \result == 5);
    ensures (1200 <= x <= 1399 ==> \result == 4);
    ensures (1400 <= x <= 1599 ==> \result == 3);
    ensures (1600 <= x <= 1799 ==> \result == 2);
    ensures (1800 <= x <= 1999 ==> \result == 1);
*/
int func(int x)
{
    int result;

    //@ assert 400 <= x <= 1999;

    if (400 <= x && x <= 599) {
        result = 8;
        //@ assert result == 8;
    } else if (600 <= x && x <= 799) {
        result = 7;
        //@ assert result == 7;
    } else if (800 <= x && x <= 999) {
        result = 6;
        //@ assert result == 6;
    } else if (1000 <= x && x <= 1199) {
        result = 5;
        //@ assert result == 5;
    } else if (1200 <= x && x <= 1399) {
        result = 4;
        //@ assert result == 4;
    } else if (1400 <= x && x <= 1599) {
        result = 3;
        //@ assert result == 3;
    } else if (1600 <= x && x <= 1799) {
        result = 2;
        //@ assert result == 2;
    } else if (1800 <= x && x <= 1999) {
        result = 1;
        //@ assert result == 1;
    } else {
        result = -1;
    }

    //@ assert result == compute_result(x);
    return result;
}
