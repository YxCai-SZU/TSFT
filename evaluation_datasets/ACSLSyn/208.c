#include <stdint.h>
#include <stdbool.h>

/* Original func: compute change to next multiple of 1000 */
/*@
    predicate valid_range(integer n) = 1 <= n <= 100000;

    logic integer compute_change(integer n) =
        (1000 - (n % 1000)) % 1000;

    lemma change_properties:
        \forall integer n;
        valid_range(n) ==>
        compute_change(n) >= 0 &&
        compute_change(n) < 1000;
*/

int32_t change_func(uint32_t n)
{
    uint32_t r;
    uint32_t change;
    
    //@ assert valid_range(n);
    
    r = n % 1000;
    change = (1000 - r) % 1000;
    
    //@ assert change == compute_change(n);
    
    return (int32_t)change;
}

/* Original func: check if interval between a and b has even length */
/*@
    predicate valid_params(integer n, integer a, integer b) =
        2 <= n <= 100 && 1 <= a < b <= n;

    logic integer interval(integer a, integer b) = b - a - 1;

    lemma interval_property:
        \forall integer n, a, b;
        valid_params(n, a, b) ==> interval(a, b) >= 0;
*/

bool interval_func(unsigned long n, unsigned long a, unsigned long b)
{
    unsigned long interval_val = b - a - 1;
    bool is_even = false;
    unsigned long count = interval_val;

    //@ assert interval_val == b - a - 1;
    //@ assert count == interval_val;

    while (count > 0)
    {
        if (count == 1)
        {
            is_even = false;
            break;
        }
        count -= 2;
    }

    if (count == 0)
    {
        is_even = true;
    }

    //@ assert is_even == (interval_val % 2 == 0);
    return is_even;
}

/* 
 * Scenario: Payment processing system - check if change amount
 * (to next whole dollar) has an even number of cents between
 * two positions in a transaction log.
 *
 * Given: n = total transaction amount in cents (1..100000)
 *        a, b = positions in transaction log (1 <= a < b <= n)
 * 
 * The synthesized function computes:
 * 1. The change (in cents) needed to round up to next dollar
 * 2. Whether the number of log entries between positions a and b is even
 * 
 * The high-level property: The change amount (mod 2) equals
 * the parity of the interval length, ensuring consistency
 * between monetary rounding and log structure.
 */
bool payment_check(uint32_t n, unsigned long a, unsigned long b)
{
    int32_t change = change_func(n);
    bool interval_even = interval_func(n, a, b);
    bool change_even = (change % 2 == 0);
    bool result = (change_even == interval_even);

    //@ assert change == compute_change(n);
    //@ assert interval_even == (interval(a, b) % 2 == 0);
    //@ assert result == (compute_change(n) % 2 == interval(a, b) % 2);
    
    return result;
}
