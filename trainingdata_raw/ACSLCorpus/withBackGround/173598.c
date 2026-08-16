#include <stdint.h>

/*@
    predicate is_nonnegative(integer x) = x >= 0;
    predicate is_small(integer x) = x < 1000;
    predicate valid_n(integer n) = 1 <= n && n <= 10000;

    logic integer mod_result(integer n) = (1000 - n % 1000) % 1000;

    lemma mod_result_nonnegative: \forall integer n; valid_n(n) ==> is_nonnegative(mod_result(n));
    lemma mod_result_small: \forall integer n; valid_n(n) ==> is_small(mod_result(n));
*/

/*@
    requires valid_n(n);
    ensures is_nonnegative(\result);
    ensures is_small(\result);
    ensures \result == mod_result(n);
*/
int32_t func(int32_t n)
{
    uint32_t n_unsigned;
    uint32_t result_unsigned;
    int32_t result;

    //@ assert valid_n(n);
    if (n < 0)
    {
        n_unsigned = (uint32_t)(-n);
    }
    else
    {
        n_unsigned = (uint32_t)n;
    }

    result_unsigned = (1000 - n_unsigned % 1000) % 1000;
    //@ assert result_unsigned == mod_result(n);
    result = (int32_t)result_unsigned;
    return result;
}

/*@
    predicate seq_len(integer len) = len == 4;
    predicate seq_index(integer i, integer v) = 
        (i == 0 ==> v == 0) &&
        (i == 1 ==> v == 3) &&
        (i == 2 ==> v == 6) &&
        (i == 3 ==> v == 9);
*/

/*@
    requires \true;
    ensures \true;
*/
void example1(void)
{
    //@ assert seq_len(4);
    //@ assert seq_index(0, 0);
    //@ assert seq_index(1, 3);
    //@ assert seq_index(2, 6);
    //@ assert seq_index(3, 9);
    //@ assert seq_index(2, 6);
    //@ assert !(\exists integer i; 0 <= i && i < 4 && seq_index(i, 15));
}
