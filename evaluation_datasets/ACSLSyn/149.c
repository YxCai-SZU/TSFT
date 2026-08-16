#include <stdint.h>

/* First function: compute_result with bounds checking */
/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 && 0 <= m <= n;

    logic integer compute_result(integer n, integer m) =
        n == 0 ? 0 :
        m >= n ? 1 :
        n - m;

    lemma result_bounds:
        \forall integer n, m;
        valid_params(n, m) ==> 0 <= compute_result(n, m) <= n;
*/

int32_t func1(uint32_t n, uint32_t m) {
    int32_t result;
    uint32_t i;

    //@ assert valid_params(n, m);

    if (n == 0) {
        //@ assert n == 0;
        result = 0;
        //@ assert result >= 0;
        //@ assert result <= n;
        return result;
    } else if (m >= n) {
        //@ assert m >= n;
        result = 1;
        //@ assert result >= 0;
        //@ assert result <= n;
        return result;
    } else {
        //@ assert n > 0 && m < n;
        result = (int32_t)n - (int32_t)m;
        i = 0;

        while (i < m) {
            //@ assert i < m;
            if ((int32_t)i + 1 < result) {
                //@ assert (int32_t)i + 1 < result;
                result = result - ((int32_t)i + 1);
                //@ assert result >= 0;
            } else {
                //@ assert (int32_t)i + 1 >= result;
                result = 0;
                //@ assert result >= 0;
            }
            i = i + 1;
            //@ assert i <= m;
        }
        //@ assert result >= 0;
        //@ assert result <= n;
        return result;
    }
}

/* Second function: compute upper bound */
/*@
    predicate valid_inputs(integer a, integer b) =
        2 <= a && a <= 20 &&
        1 <= b && b <= 20;

    logic integer upper_bound(integer a, integer b) =
        b + (a - 2) / 2;
*/

uint32_t func2(uint32_t a, uint32_t b)
{
    uint32_t result;
    result = b;

    if (a > 2)
    {
        //@ assert a > 2;
        result = result + (a - 2) / 2;
        //@ assert result == b + (a - 2) / 2;
    }
    else
    {
        //@ assert a <= 2;
        //@ assert result == b;
    }

    return result;
}

/* Synthesized function: Simulates a resource allocation scenario where
   we compute available slots (func1) and then apply a capacity bound (func2)
   to ensure the final allocation doesn't exceed system limits.
   Real-world context: A memory pool allocator that first computes
   available blocks from a bitmap, then caps allocation based on
   a predefined capacity table. */

/*@
    predicate valid_allocation(integer n, integer m, integer a, integer b) =
        valid_params(n, m) && valid_inputs(a, b) &&
        n <= 100 && b <= 20;

    logic integer combined_upper_bound(integer n, integer m, integer a, integer b) =
        (n == 0 ? 0 :
         m >= n ? 1 :
         n - m) <= (b + (a - 2) / 2) ?
        (n == 0 ? 0 :
         m >= n ? 1 :
         n - m) :
        (b + (a - 2) / 2);
*/

uint32_t resource_allocator(uint32_t n, uint32_t m, uint32_t a, uint32_t b) {
    int32_t available_slots;
    uint32_t capacity_limit;
    uint32_t final_allocation;

    available_slots = func1(n, m);
    //@ assert available_slots >= 0 && available_slots <= n;

    capacity_limit = func2(a, b);
    //@ assert capacity_limit <= upper_bound(a, b);

    if ((uint32_t)available_slots <= capacity_limit) {
        final_allocation = (uint32_t)available_slots;
    } else {
        final_allocation = capacity_limit;
    }

    //@ assert final_allocation <= (uint32_t)available_slots && final_allocation <= capacity_limit;

    return final_allocation;
}
