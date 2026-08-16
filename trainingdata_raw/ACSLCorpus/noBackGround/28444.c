#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures (((\result) >= 0 || (\result) == -1) &&
        ((\result) >= 0 ==>
            (\result) * 8 / 100 == (a) &&
            (\result) * 10 / 100 == (b)));
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t total;
    uint32_t x;
    int32_t result;

    total = a + b + 1;
    x = 1;
    result = -1;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100);
    //@ assert total == ((a) + (b) + 1);
    //@ assert 1 <= x && x <= total;

    /*@
        loop invariant 1 <= x && x <= total;
        loop invariant total == a + b + 1;
        loop invariant result == -1 || (result >= 0 && result * 8 / 100 == a && result * 10 / 100 == b);
        loop assigns x, result;
        loop variant total - x;
    */
    while (x < total)
    {
        //@ assert x * 10 <= 2010;
        if (x * 8 / 100 == a && x * 10 / 100 == b)
        {
            result = (int32_t)x;
            //@ assert (((result) >= 0 || (result) == -1) &&         ((result) >= 0 ==>             (result) * 8 / 100 == (a) &&             (result) * 10 / 100 == (b)));
            return result;
        }
        x += 1;
        //@ assert x <= total;
    }

    //@ assert (((result) >= 0 || (result) == -1) &&         ((result) >= 0 ==>             (result) * 8 / 100 == (a) &&             (result) * 10 / 100 == (b)));
    return result;
}
