#include <stdint.h>

/*@
    predicate in_range(integer x) = 400 <= x <= 1999;

    logic integer compute_result(integer x) =
        x <= 600 ? 8 :
        x <= 800 ? 7 :
        x <= 1000 ? 6 :
        x <= 1200 ? 5 :
        x <= 1500 ? 4 :
        x <= 1800 ? 3 :
        x <= 1999 ? 2 : -1;

    lemma result_property:
        \forall integer x;
            in_range(x) ==>
            (compute_result(x) == 1) ==>
            (x <= 600 ==> compute_result(x) == 8) &&
            (600 < x && x <= 800 ==> compute_result(x) == 7) &&
            (800 < x && x <= 1000 ==> compute_result(x) == 6) &&
            (1000 < x && x <= 1200 ==> compute_result(x) == 5) &&
            (1200 < x && x <= 1500 ==> compute_result(x) == 4) &&
            (1500 < x && x <= 1800 ==> compute_result(x) == 3) &&
            (1800 < x && x <= 1999 ==> compute_result(x) == 2) &&
            (x >= 400 ==> compute_result(x) == 1) ==> compute_result(x) == 1;
*/

/*@
    requires 400 <= x <= 1999;
    ensures \result == compute_result(x);
    ensures (\result == 1) ==>
            (x <= 600 ==> \result == 8) &&
            (600 < x && x <= 800 ==> \result == 7) &&
            (800 < x && x <= 1000 ==> \result == 6) &&
            (1000 < x && x <= 1200 ==> \result == 5) &&
            (1200 < x && x <= 1500 ==> \result == 4) &&
            (1500 < x && x <= 1800 ==> \result == 3) &&
            (1800 < x && x <= 1999 ==> \result == 2) &&
            (x >= 400 ==> \result == 1) ==> \result == 1;
*/
int64_t func(int64_t x)
{
    int64_t result;
    
    if (x <= 600) {
        result = 8;
    } else if (x <= 800) {
        result = 7;
    } else if (x <= 1000) {
        result = 6;
    } else if (x <= 1200) {
        result = 5;
    } else if (x <= 1500) {
        result = 4;
    } else if (x <= 1800) {
        result = 3;
    } else if (x <= 1999) {
        result = 2;
    } else {
        result = -1;
    }
    
    //@ assert result == compute_result(x);
    
    return result;
}
