#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 100000 &&
        0 <= (k) && (k) <= (n) - 1);
    ensures \result == n - 1 - k || \result == k;
    assigns \nothing;
*/
long func(long n, long k)
{
    long steps_left_val;
    long steps_right_val;
    long result;

    //@ assert (1 <= (n) && (n) <= 100000 &&         0 <= (k) && (k) <= (n) - 1);
    steps_left_val = n - 1 - k;
    steps_right_val = k;

    if (steps_left_val < steps_right_val)
    {
        //@ assert steps_left_val == n - 1 - k || steps_left_val == k;
        result = steps_left_val;
    }
    else
    {
        //@ assert steps_right_val == n - 1 - k || steps_right_val == k;
        result = steps_right_val;
    }

    //@ assert result == n - 1 - k || result == k;
    return result;
}
