#include <stdint.h>

/*@
    requires ((l) >= 1 && (r) >= 1 && (d) >= 1 &&
        (l) <= (r) && (r) <= 100 && (d) <= 100);
    ensures \result >= 0;
    ensures \result <= (r - l + 1);
    assigns \nothing;
*/
uint64_t func(int64_t l, int64_t r, int64_t d)
{
    uint64_t count = 0;
    int64_t i = l;
    
    /*@
        loop invariant l >= 1 && r >= 1 && d >= 1;
        loop invariant l <= r && r <= 100 && d <= 100;
        loop invariant l <= i && i <= r + 1;
        loop invariant count >= 0;
        loop invariant count <= (uint64_t)(i - l);
        loop assigns i, count;
        loop variant r - i + 1;
    */
    while (i <= r)
    {
        int divisible = 0;
        int64_t temp = i;
        
        /*@
            loop invariant l >= 1 && r >= 1 && d >= 1;
            loop invariant l <= r && r <= 100 && d <= 100;
            loop invariant temp >= 0;
            loop invariant temp <= i;
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= d)
        {
            temp -= d;
        }
        
        if (temp == 0)
        {
            divisible = 1;
        }
        
        if (divisible)
        {
            //@ assert count + 1 <= (uint64_t)(i - l + 1);
            count += 1;
        }
        
        i += 1;
    }
    
    //@ assert count <= (uint64_t)(r - l + 1);
    return count;
}
