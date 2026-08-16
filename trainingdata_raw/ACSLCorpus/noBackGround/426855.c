#include <stdbool.h>
#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == (((c) == 0) ? (a) + (b) : (b) + (d));
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d)
{
    bool is_zero_var;
    uint64_t ans;

    is_zero_var = (c == 0);
    //@ assert is_zero_var == (c == 0);

    if (is_zero_var)
    {
        ans = a + b;
        //@ assert is_zero_var && ans == a + b;
    }
    else
    {
        ans = b + d;
        //@ assert !is_zero_var && ans == b + d;
    }

    //@ assert ans == (((c) == 0) ? (a) + (b) : (b) + (d));
    return ans;
}
