#include <limits.h>

/*@
    requires (1 <= (a) <= 50 &&
        1 <= (b) <= 50 &&
        1 <= (c) <= 50 &&
        1 <= (k) <= 50);
    ensures \result >= -c;
    ensures \result <= a + b;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int result = 0;
    int k_mut = k;

    //@ assert (1 <= (a) <= 50 &&         1 <= (b) <= 50 &&         1 <= (c) <= 50 &&         1 <= (k) <= 50);
    
    if (a <= k_mut)
    {
        result += a;
        k_mut -= a;
    }
    else
    {
        //@ assert k >= -c && k <= a + b;
        return k;
    }

    //@ assert result == a && k_mut == k - a;

    if (b <= k_mut)
    {
        k_mut -= b;
    }
    else
    {
        result -= k_mut - b;
        //@ assert result >= -c && result <= a + b;
        return result;
    }

    //@ assert k_mut == k - a - b;

    if (c <= k_mut)
    {
        result -= c;
    }
    else
    {
        result -= k_mut;
    }

    //@ assert result >= -c;
    //@ assert result <= a + b;
    return result;
}
