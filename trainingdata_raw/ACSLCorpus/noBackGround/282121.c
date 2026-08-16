#include <stdint.h>

/*@
    requires (1 <= (x) <= 100 &&
        1 <= (y) <= 100 &&
        (y) % 2 == 0);
    ensures \result == x + ((y) / 2);
    assigns \nothing;
*/
int64_t func(int64_t x, int64_t y)
{
    int64_t result;
    int64_t half_y;
    int64_t count;
    int64_t temp_y;

    result = x;
    half_y = 0;
    count = 0;
    temp_y = y;

    /*@
        loop invariant 0 <= count;
        loop invariant count * 2 <= y;
        loop invariant half_y == 0;
        loop invariant temp_y == y - 2 * count;
        loop invariant (1 <= (x) <= 100 &&
        1 <= (y) <= 100 &&
        (y) % 2 == 0);
        loop assigns temp_y, count;
        loop variant temp_y;
    */
    while (temp_y >= 2)
    {
        temp_y -= 2;
        count += 1;
    }

    half_y = count;

    result += half_y;

    //@ assert result == x + half_y;
    //@ assert half_y == ((y) / 2);
    //@ assert result == x + ((y) / 2);

    return result;
}
