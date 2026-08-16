#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 10000;

    logic integer compute_result(integer n) =
        (1000 - n % 1000) % 1000;

    lemma result_properties:
        \forall integer n;
        is_valid_n(n) ==>
            compute_result(n) >= 0 &&
            compute_result(n) < 1000 &&
            compute_result(n) == (1000 - n % 1000) % 1000;
*/

/*@
    requires is_valid_n(n);
    ensures \result >= 0;
    ensures \result < 1000;
    ensures \result == compute_result(n);
*/
int32_t func(int32_t n)
{
    uint32_t n_unsigned;
    uint32_t result_unsigned;
    int32_t result;

    //@ assert is_valid_n(n);
    
    if (n < 0)
    {
        n_unsigned = (uint32_t)(-n);
    }
    else
    {
        n_unsigned = (uint32_t)n;
    }

    //@ assert n_unsigned == (n < 0 ? (uint32_t)(-n) : (uint32_t)n);
    
    result_unsigned = (1000 - n_unsigned % 1000) % 1000;
    
    //@ assert result_unsigned == compute_result(n_unsigned);
    //@ assert result_unsigned >= 0;
    //@ assert result_unsigned < 1000;
    
    result = (int32_t)result_unsigned;
    
    //@ assert result == (int32_t)compute_result(n_unsigned);
    //@ assert result >= 0;
    //@ assert result < 1000;
    //@ assert result == compute_result(n);
    
    return result;
}
