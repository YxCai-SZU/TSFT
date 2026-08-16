#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer safe_product(integer a, integer b) =
        a * b + 1;

    lemma product_bound: \forall integer a, b;
        valid_range(a, b) ==> a * b <= 10000;

    lemma result_positive: \forall integer a, b, r;
        valid_range(a, b) && r == safe_product(a, b) && r < 2147483648 ==> r > 0;
*/

/*@
    requires valid_range(a, b);
    ensures \result == (int)safe_product(a, b) || \result == -1;
    ensures \result != -1 ==> \result > 0;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;
    uint32_t max_i32 = 2147483648U;

    //@ assert valid_range(a, b);
    //@ assert a * b <= 10000;
    
    result = a * b + 1U;

    if (result >= max_i32)
    {
        //@ assert result >= max_i32;
        return -1;
    }
    else
    {
        //@ assert result < max_i32;
        //@ assert result > 0;
        return (int32_t)result;
    }
}
