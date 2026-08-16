#include <stdint.h>

/*@ requires (1 <= (r) <= 100);
    ensures \result == 2 * r * (314159)/ (100000);
    assigns \nothing;
 */
int64_t func(int64_t r)
{
    int64_t pi = 314159;
    int64_t scale = 100000;
    int64_t numerator;
    int64_t ans = 0;
    int64_t count = 0;
    
    //@ assert pi == (314159);
    //@ assert scale == (100000);
    
    numerator = 2 * r * pi;
    
    //@ assert numerator == 2 * r * (314159);
    //@ assert 0 <= numerator <= 2 * 100 * (314159);
    
    /*@ loop invariant (1 <= (r) <= 100);
        loop invariant pi == (314159);
        loop invariant scale == (100000);
        loop invariant numerator >= 0;
        loop invariant ans == count;
        loop invariant numerator == 2 * r * (314159)- count * (100000);
        loop assigns numerator, ans, count;
        loop variant numerator;
     */
    while (numerator >= scale)
    {
        numerator -= scale;
        ans += 1;
        count += 1;
    }
    
    return ans;
}
