#include <stdint.h>

/*@
    predicate bounds_2_100(integer v) = 2 <= v && v <= 100;

    logic integer subtract_one(integer v) = v - 1;
    logic integer multiply(integer a, integer b) = a * b;

    lemma subtract_one_bounds:
        \forall integer a; bounds_2_100(a) ==> 1 <= subtract_one(a) <= 99;

    lemma multiply_bounds:
        \forall integer a, b;
            1 <= a <= 99 && 1 <= b <= 99 ==>
            0 <= multiply(a, b) < 10000;
*/

/*@
    requires bounds_2_100(A);
    requires bounds_2_100(B);
    ensures \result == multiply(subtract_one(A), subtract_one(B));
*/
int32_t func(int32_t A, int32_t B)
{
    // Variable declarations at scope top
    int32_t result;

    //@ assert bounds_2_100(A);
    //@ assert bounds_2_100(B);
    //@ assert 1 <= subtract_one(A) <= 99;
    //@ assert 1 <= subtract_one(B) <= 99;
    //@ assert 0 <= multiply(subtract_one(A), subtract_one(B));
    //@ assert multiply(subtract_one(A), subtract_one(B)) < 10000;

    result = (A - 1) * (B - 1);
    return result;
}
