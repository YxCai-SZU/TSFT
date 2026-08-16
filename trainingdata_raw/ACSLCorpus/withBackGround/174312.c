#include <stdbool.h>

/*@
    predicate valid_array(int *a, integer len) =
        len == 3 &&
        \forall integer i; 0 <= i < len ==> 1 <= a[i] && a[i] <= 100;

    logic integer diff1(int *a) = a[1] - a[0];
    logic integer diff2(int *a) = a[2] - a[1];

    lemma diff_bounds:
        \forall int *a; valid_array(a, 3) ==> -99 <= diff1(a) <= 99 && -99 <= diff2(a) <= 99;
*/

/*@
    requires \valid(a+(0..2));
    requires valid_array(a, 3);
    ensures \result == (diff1(a) == diff2(a));
    assigns \nothing;
*/
bool func(int *a) {
    int diff1;
    int diff2;

    //@ assert valid_array(a, 3);
    //@ assert -99 <= a[1] - a[0] <= 99;
    //@ assert -99 <= a[2] - a[1] <= 99;

    diff1 = a[1] - a[0];
    diff2 = a[2] - a[1];

    //@ assert diff1 == diff1(a);
    //@ assert diff2 == diff2(a);

    if (diff1 == diff2) {
        //@ assert diff1(a) == diff2(a);
        return true;
    } else {
        //@ assert diff1(a) != diff2(a);
        return false;
    }
}
