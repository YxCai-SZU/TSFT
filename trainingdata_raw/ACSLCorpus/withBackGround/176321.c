#include <stdint.h>

/*@
    predicate valid_range(integer N) = 1 <= N && N <= 10000;

    logic integer compute_result(integer N) =
        (1000 - (N % 1000)) % 1000;

    lemma result_properties:
        \forall integer N;
        valid_range(N) ==>
        compute_result(N) >= 0 &&
        compute_result(N) < 1000;
*/

/*@
    requires valid_range(N);
    ensures \result >= 0;
    ensures \result < 1000;
    ensures \result == compute_result(N);
*/
int64_t func(int64_t N)
{
    uint64_t N_unsigned;
    uint64_t remainder;
    uint64_t result;
    int64_t final_result;

    // Convert to unsigned
    if (N < 0)
    {
        N_unsigned = (uint64_t)(-N);
    }
    else
    {
        N_unsigned = (uint64_t)N;
    }

    // Calculate remainder
    remainder = N_unsigned % 1000;

    // Calculate result using unsigned arithmetic
    result = (1000 - remainder) % 1000;

    //@ assert result >= 0;
    //@ assert result < 1000;
    //@ assert result == (uint64_t)compute_result(N);

    // Convert back to signed if necessary
    if (N < 0)
    {
        final_result = -(int64_t)result;
    }
    else
    {
        final_result = (int64_t)result;
    }

    return final_result;
}
