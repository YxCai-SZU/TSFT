#include <stdint.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (k) >= 1 && (k) <= (a) + (b) + (c) && (k) <= 2000000000);
    ensures \result <= a;
    ensures \result >= -c;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t count = 0;
    int32_t remaining_k = k;
    
    //@ assert count == 0 && remaining_k == k;
    
    if (remaining_k < a)
    {
        count += remaining_k;
        //@ assert count <= a;
        //@ assert count >= -c;
        return count;
    }
    
    remaining_k -= a;
    count += a;
    
    //@ assert count == a && remaining_k == k - a;
    
    if (remaining_k < b)
    {
        //@ assert count <= a;
        //@ assert count >= -c;
        return count;
    }
    
    remaining_k -= b;
    //@ assert remaining_k == k - a - b;
    
    count -= remaining_k;
    //@ assert count == a - (k - a - b);
    
    //@ assert count >= -c;
    return count;
}
