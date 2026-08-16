#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (((2)* (314159)* (r)) / (100000));
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi = 314159;
    int64_t two = 2;
    int64_t scale = 100000;
    int64_t numerator = two * pi * r;
    int64_t ans = 0;
    int64_t count = 0;
    
    //@ assert two == (2);
    //@ assert pi == (314159);
    //@ assert scale == (100000);
    //@ assert numerator == (2)* (314159)* r;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == (314159);
        loop invariant two == (2);
        loop invariant scale == (100000);
        loop invariant numerator >= 0;
        loop invariant numerator == (2)* (314159)* r - count * (100000);
        loop invariant count >= 0;
        loop invariant ans == count;
        loop invariant ans * (100000)+ numerator == (2)* (314159)* r;
        loop assigns numerator, ans, count;
        loop variant numerator;
    */
    while (numerator >= scale)
    {
        numerator -= scale;
        ans += 1;
        count += 1;
    }
    
    //@ assert ans == (((2)* (314159)* (r)) / (100000));
    return ans;
}

int main(void)
{
    return 0;
}
