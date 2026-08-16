#include <stdint.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 &&
        1 <= (k) && (k) <= (a) + (b) + (c) && (a) + (b) + (c) <= 2000000000);
    ensures \result <= a;
    ensures \result == ((k) <= (a) ? (k) :
        (k) <= (a) + (b) ? (a) :
        (a) - ((k) - (a) - (b)));
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t k_remaining;
    int64_t sum;
    
    k_remaining = k;
    sum = 0;
    
    //@ assert k_remaining == k && sum == 0;
    if (k_remaining > a)
    {
        sum += a;
        k_remaining -= a;
        //@ assert k_remaining == k - a && sum == a;
    }
    else
    {
        sum += k_remaining;
        k_remaining = 0;
        //@ assert k_remaining == 0 && sum == k;
    }
    
    //@ assert k_remaining >= 0;
    if (k_remaining > b)
    {
        k_remaining -= b;
        //@ assert k_remaining == k - a - b;
    }
    else
    {
        k_remaining = 0;
        //@ assert k_remaining == 0;
    }
    
    //@ assert k_remaining >= 0;
    if (k_remaining > 0)
    {
        sum -= k_remaining;
        k_remaining = 0;
        //@ assert sum == a - (k - a - b);
    }
    
    //@ assert k_remaining == 0;
    return sum;
}
