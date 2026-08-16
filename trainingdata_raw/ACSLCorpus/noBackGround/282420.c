#include <stdint.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures \result >= 0;
    ensures \result == ((((x)) / 500) * 1000 + ((((x)) % 500) / 5) * 5);
*/
int64_t func(int64_t x)
{
    int64_t result;
    int64_t temp_x;
    int64_t count_500;
    int64_t count_5;
    
    result = 0;
    temp_x = x;
    count_500 = 0;
    count_5 = 0;

    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant count_500 >= 0;
        loop invariant temp_x == x - 500 * count_500;
        loop invariant (0 <= (x) <= 1000000000);
        loop assigns temp_x, count_500;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        count_500 = count_500 + 1;
        temp_x = temp_x - 500;
        //@ assert temp_x == x - 500 * count_500;
    }

    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant count_5 >= 0;
        loop invariant temp_x == x - 500 * count_500 - 5 * count_5;
        loop invariant (0 <= (x) <= 1000000000);
        loop assigns temp_x, count_5;
        loop variant temp_x;
    */
    while (temp_x >= 5)
    {
        count_5 = count_5 + 1;
        temp_x = temp_x - 5;
        //@ assert temp_x == x - 500 * count_500 - 5 * count_5;
    }

    result = count_500 * 1000 + count_5 * 5;
    
    //@ assert count_500 == ((x) / 500);
    //@ assert count_5 == (((x) % 500) / 5);
    //@ assert result == ((((x)) / 500) * 1000 + ((((x)) % 500) / 5) * 5);
    
    return result;
}
