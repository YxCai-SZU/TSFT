#include <stdint.h>

/*@
    predicate valid_l(integer l) = 1 <= l <= 1000;

    logic integer cube(integer l) = l * l * l;

    logic integer expected_result(integer l) = cube(l) / 27;

    lemma cube_bound: \forall integer l; valid_l(l) ==> cube(l) <= 1000000000;
    lemma result_bound: \forall integer l; valid_l(l) ==> expected_result(l) <= 37037037;
*/

/*@
    requires valid_l(l);
    ensures \result == expected_result(l);
    assigns \nothing;
*/
int32_t func(uint32_t l) {
    // Variable declarations at scope top
    int32_t result;
    int32_t count;
    const int32_t divisor = 27;

    // Precondition check
    //@ assert valid_l(l);

    // Overflow safety
    //@ assert l * l <= 1000000;
    //@ assert cube(l) <= 1000000000;

    result = (int32_t)(l * l * l);
    count = 0;

    /*@
        loop invariant 1 <= l <= 1000;
        loop invariant 0 <= result <= 1000000000;
        loop invariant 0 <= count <= 37037037;
        loop invariant result == cube(l) - count * divisor;
        loop assigns result, count;
        loop variant result;
    */
    while (result >= divisor) {
        result -= divisor;
        count += 1;
    }

    // Postcondition verification
    //@ assert count == expected_result(l);
    return count;
}
