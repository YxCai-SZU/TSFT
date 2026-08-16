#include <stdint.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == n * 800 - (n / 15) * 200;
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t x = 800;
    int32_t y = 200;
    int32_t result = 0;
    uint32_t count = 0;
    uint32_t limit = n / 15;

    /*@
        loop invariant 0 <= count <= n;
        loop invariant result == ((count) * 800);
        loop assigns result, count;
        loop variant n - count;
    */
    while (count < n)
    {
        //@ assert count < n;
        result += x;
        count += 1;
        //@ assert result == ((count) * 800);
    }

    //@ assert result == ((n) * 800);
    //@ assert result == n * 800;

    count = 0;

    /*@
        loop invariant 0 <= count <= limit;
        loop invariant result == ((n) * 800 - (count) * 200);
        loop assigns result, count;
        loop variant limit - count;
    */
    while (count < limit)
    {
        //@ assert count < limit;
        result -= y;
        count += 1;
        //@ assert result == ((n) * 800 - (count) * 200);
    }

    //@ assert result == ((n) * 800 - (limit) * 200);
    //@ assert result == n * 800 - limit * 200;
    //@ assert limit == n / 15;

    return result;
}

