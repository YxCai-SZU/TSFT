#include <stdint.h>

/*@
    predicate bounds(integer n, integer a, integer b) =
        1 <= n && n <= 20 &&
        1 <= a && a <= 50 &&
        1 <= b && b <= 50;

    logic integer safe_mul(integer n, integer a) = n * a;

    lemma mul_bounds:
        \forall integer n, integer a;
        bounds(n, a, 0) ==> 1 <= safe_mul(n, a) && safe_mul(n, a) <= 1000;
*/

/*@
    requires bounds(n, a, b);
    ensures \result >= 0;
    ensures \result <= b;
    ensures \result == n * a || \result == b;
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t a, uint32_t b)
{
    // Variable declarations at top
    int32_t ret;
    uint32_t product;

    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert 1 <= b && b <= 50;

    //@ assert n * a <= 1000;
    //@ assert n * a >= 1;

    product = n * a;

    if (product < b)
    {
        ret = (int32_t)product;
    }
    else
    {
        ret = (int32_t)b;
    }

    //@ assert ret >= 0;
    //@ assert ret <= b;
    //@ assert ret == n * a || ret == b;

    return ret;
}
