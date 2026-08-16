#include <stdbool.h>
/*@
    predicate is_valid_range(integer l) =
        1 <= l && l <= 1000;

    logic integer cube(integer l) = l * l * l;

    logic integer expected_result(integer l) = cube(l) / 27;

    lemma cube_bound:
        \forall integer l; is_valid_range(l) ==> cube(l) <= 1000000000;
*/

/*@
    requires is_valid_range(l);
    ensures \result == expected_result(l);
    assigns \nothing;
*/
int func(int l) {
    // Variable declarations at scope top
    int res;
    int count;
    int divisor;

    //@ assert is_valid_range(l);
    //@ assert cube(l) <= 1000000000;

    res = l * l * l;
    count = 0;
    divisor = 27;

    /*@
        loop invariant 0 <= res;
        loop invariant 0 <= count;
        loop invariant res == cube(l) - count * divisor;
        loop invariant res >= 0 ==> count == (cube(l) - res) / divisor;
        loop assigns res, count;
        loop variant res;
    */
    while (res >= divisor) {
        //@ assert res >= divisor;
        res -= divisor;
        count += 1;
        //@ assert res == cube(l) - count * divisor;
    }

    //@ assert res == cube(l) - count * divisor;
    //@ assert res < divisor;
    //@ assert count == expected_result(l);
    return count;
}
