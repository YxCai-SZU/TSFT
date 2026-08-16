#include <stdint.h>
#include <stdbool.h>

/*@ predicate xor_bounded(uint32_t a, uint32_t b) =
      (a ^ b) <= 0xFFFFFFFF;
*/

/*@ lemma xor_identity: \forall uint32_t a, b;
      xor_bounded(a, b) ==> (a ^ b) == (a ^ b);
*/

uint32_t xor_func(uint32_t a, uint32_t b) {
    uint32_t res;
    
    //@ assert a <= 0xFFFFFFFF && b <= 0xFFFFFFFF;
    res = a ^ b;
    
    //@ assert res <= 0xFFFFFFFF;
    return res;
}

/*@
    predicate valid_range(integer a, integer b, integer x) =
        0 <= a <= b <= 1000000000000000000 &&
        1 <= x <= 1000000000000000000;

    logic integer floor_div(integer n, integer d) = n / d;

    logic integer func_spec(integer a, integer b, integer x) =
        floor_div(b, x) - floor_div(a, x) + (a % x == 0 ? 1 : 0);

    lemma division_monotonic:
        \forall integer a, b, x;
        valid_range(a, b, x) ==> floor_div(b, x) >= floor_div(a, x);
*/

uint64_t count_multiples(uint64_t a, uint64_t b, uint64_t x)
{
    uint64_t extra;
    uint64_t result;

    //@ assert a <= b;
    //@ assert x >= 1;
    //@ assert x <= 1000000000000000000;
    //@ assert b / x >= a / x;

    if (a % x == 0)
        extra = 1;
    else
        extra = 0;

    result = b / x - a / x + extra;
    return result;
}

/*@
    predicate is_seven(integer x, integer y) =
        x == 7 || y == 7 || x + y == 7;
*/

bool check_seven(unsigned long x, unsigned long y)
{
    bool result;
    unsigned long sum;

    if (x == 7 || y == 7)
    {
        result = true;
    }
    else
    {
        sum = x + y;
        if (sum == 7)
        {
            result = true;
        }
        else
        {
            //@ assert x != 7 && y != 7 && x + y != 7;
            result = false;
        }
    }

    return result;
}

/*@
    predicate is_within_bounds(integer val) =
        val >= -1000000000 && val <= 1000000000;
*/

int64_t negate_func(int64_t x)
{
    int64_t result;
    result = x;
    result = -result;
    //@ assert result == -x;
    return result;
}

/*@
    predicate valid_checksum(integer xor_val, integer count, integer negated_sum) =
        xor_val <= 0xFFFFFFFF &&
        count >= 0 &&
        negated_sum >= -1000000000 && negated_sum <= 1000000000;
*/

int64_t validate_checksum(uint64_t start, uint64_t end, uint64_t divisor,
                          unsigned long a, unsigned long b,
                          int64_t initial_val)
{
    uint32_t xor_result;
    uint64_t count_result;
    bool seven_related;
    int64_t final_val;

    /* Step 1: XOR operation on protocol header fields */
    xor_result = xor_func((uint32_t)(start & 0xFFFFFFFF), (uint32_t)(end & 0xFFFFFFFF));

    /* Step 2: Count multiples in range (packet count validation) */
    count_result = count_multiples(start, end, divisor);

    /* Step 3: Check if packet identifiers are 7-related */
    seven_related = check_seven(a, b);

    /* Step 4: Negate initial checksum value */
    final_val = negate_func(initial_val);

    return final_val;
}
