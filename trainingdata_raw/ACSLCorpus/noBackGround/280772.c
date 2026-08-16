#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * ((r)) * 314159) / 100000);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi;
    int64_t scale;
    int64_t numerator;
    int64_t result;
    int64_t count;
    
    pi = 314159;
    scale = 100000;
    numerator = 2 * r * pi;
    result = 0;
    count = 0;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314159;
        loop invariant scale == 100000;
        loop invariant numerator >= 0;
        loop invariant result == count;
        loop invariant numerator == (2 * (r) * 314159) - count * scale;
        loop invariant 0 <= count <= ((2 * ((r)) * 314159) / 100000);
        loop assigns numerator, result, count;
        loop variant numerator;
    */
    while (numerator >= scale)
    {
        //@ assert numerator >= scale;
        numerator -= scale;
        result += 1;
        count += 1;
    }
    
    //@ assert result == ((2 * ((r)) * 314159) / 100000);
    return result;
}

int main()
{
    return 0;
}
