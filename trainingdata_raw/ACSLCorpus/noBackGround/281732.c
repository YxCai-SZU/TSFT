#include <limits.h>

/*@
    requires (1 <= (a) <= 1000000000 &&
        1 <= (b) <= 1000000000 &&
        1 <= (c) <= 1000000000 &&
        1 <= (k) <= 1000000000 &&
        (a) + (b) + (c) >= (k));
    ensures ((\result) >= -(k) && (\result) <= (k));
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int result = 0;
    int remaining_k = k;
    int old_result;
    int old_remaining_k;

    //@ assert remaining_k >= 0;
    //@ assert result == 0;

    if (remaining_k >= a)
    {
        result += a;
        remaining_k -= a;
        //@ assert result == a;
        //@ assert remaining_k == k - a;
    }
    else
    {
        result += remaining_k;
        remaining_k = 0;
        //@ assert result == k;
        //@ assert remaining_k == 0;
    }

    //@ assert result >= 0;
    //@ assert remaining_k >= 0;

    old_remaining_k = remaining_k;
    old_result = result;

    if (remaining_k >= b)
    {
        remaining_k -= b;
        //@ assert remaining_k == old_remaining_k - b;
    }
    else
    {
        remaining_k = 0;
        //@ assert remaining_k == 0;
    }

    //@ assert remaining_k >= 0;
    result -= remaining_k;
    //@ assert result == old_result - remaining_k;

    //@ assert ((result) >= -(k) && (result) <= (k));
    return result;
}
