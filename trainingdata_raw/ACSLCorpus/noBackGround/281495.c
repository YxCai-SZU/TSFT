#include <stdint.h>

/*@
    requires (0 <= (a) && 0 <= (b) && 0 <= (c) &&
        1 <= (k) && (k) <= (a) + (b) + (c) && (k) <= 2000000000);
    ensures \result == ((k) <= (a) ? (k) :
        (k) <= (a) + (b) ? (a) :
        (k) <= (a) + (b) + (c) ? (a) - ((k) - (a) - (b)) :
        (a) - (c));
    ensures \result <= k;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t sum = 0;
    int64_t k_remaining = k;

    //@ assert (0 <= (a) && 0 <= (b) && 0 <= (c) &&         1 <= (k) && (k) <= (a) + (b) + (c) && (k) <= 2000000000);
    
    // Use all the positive values in A
    if (k_remaining >= a)
    {
        sum += a;
        k_remaining -= a;
    }
    else
    {
        sum += k_remaining;
        k_remaining = 0;
    }
    
    //@ assert sum <= a && sum <= k;
    
    // Use all the zeros in B
    if (k_remaining >= b)
    {
        k_remaining -= b;
    }
    else
    {
        k_remaining = 0;
    }
    
    //@ assert k_remaining <= k - sum;
    
    // Use all the negative values in C
    if (k_remaining >= c)
    {
        sum -= c;
        k_remaining -= c;
    }
    else
    {
        sum -= k_remaining;
        k_remaining = 0;
    }
    
    //@ assert sum == ((k) <= (a) ? (k) :         (k) <= (a) + (b) ? (a) :         (k) <= (a) + (b) + (c) ? (a) - ((k) - (a) - (b)) :         (a) - (c));
    
    return sum;
}
