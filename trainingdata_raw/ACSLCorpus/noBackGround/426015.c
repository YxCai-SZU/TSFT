#include <limits.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0);
    requires (1 <= (k) <= (a) + (b) + (c) <= 2000000000 && (k) <= (a) + (b));
    ensures \result <= k;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int k_remaining = k;
    int sum = 0;
    int a_remaining = a;
    int b_remaining = b;
    
    // Use all the positive integers first
    //@ assert a_remaining >= 0;
    if (a_remaining > k_remaining)
    {
        sum += k_remaining;
        //@ assert sum <= k;
        return sum;
    }
    else
    {
        k_remaining -= a_remaining;
        sum += a_remaining;
    }
    
    // Use all the zeros
    //@ assert b_remaining >= 0;
    if (b_remaining > k_remaining)
    {
        //@ assert sum <= k;
        return sum;
    }
    else
    {
        k_remaining -= b_remaining;
    }
    
    // Use the negative integers
    int neg_used = 0;
    /*@
        loop invariant 0 <= neg_used <= k_remaining;
        loop invariant sum <= k;
        loop assigns neg_used, sum, k_remaining;
        loop variant k_remaining - neg_used;
    */
    while (neg_used < k_remaining)
    {
        sum -= 1;
        neg_used += 1;
    }
    
    //@ assert sum <= k;
    return sum;
}
