#include <stdint.h>

/*@
    predicate valid_l(integer l) = 1 <= l <= 1000;

    logic integer cube(integer l) = l * l * l;

    lemma cube_bounds: \forall integer l; valid_l(l) ==> 0 <= cube(l) <= 1000000000;
*/

/*@
    requires valid_l(l);
    ensures \result == cube(l) / 27;
    assigns \nothing;
*/
int64_t func(uint32_t l)
{
    // Variable declarations at scope top
    uint32_t cube;
    uint32_t result = 0;

    // Precondition verification
    //@ assert valid_l(l);

    // Calculate l * l * l with overflow checks
    //@ assert l * l <= 1000 * 1000;
    //@ assert l * l * l <= 1000000000;
    cube = l * l * l;

    /*@
        loop invariant 0 <= cube <= cube(l);
        loop invariant result * 27 + cube == cube(l);
        loop invariant 0 <= result <= cube(l) / 27;
        loop assigns cube, result;
        loop variant cube;
    */
    while (cube >= 27)
    {
        cube -= 27;
        result += 1;
    }

    // Postcondition verification
    //@ assert result == cube(l) / 27;

    return (int64_t)result;
}
