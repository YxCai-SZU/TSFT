#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (((x) / 500) * 1000 + ((x) % 500 / 5) * 5);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t result = 0;
    uint32_t remaining_x = x;
    uint32_t count_500 = 0;
    uint32_t count_5 = 0;
    
    //@ assert (1 <= (x) <= 100000);
    //@ assert 0 <= remaining_x <= x;
    
    /*@
        loop invariant 1 <= x <= 100000;
        loop invariant 0 <= remaining_x <= x;
        loop invariant count_500 <= x / 500;
        loop invariant remaining_x == x - 500 * count_500;
        loop assigns remaining_x, count_500;
        loop variant remaining_x;
    */
    while (remaining_x >= 500)
    {
        //@ assert remaining_x >= 500;
        remaining_x -= 500;
        count_500 += 1;
        //@ assert remaining_x == x - 500 * count_500;
    }
    
    //@ assert remaining_x == x - 500 * count_500;
    result += count_500 * 1000;
    
    /*@
        loop invariant 1 <= x <= 100000;
        loop invariant 0 <= remaining_x <= x;
        loop invariant count_500 <= x / 500;
        loop invariant count_5 <= (x - 500 * count_500) / 5;
        loop invariant remaining_x == x - 500 * count_500 - 5 * count_5;
        loop assigns remaining_x, count_5;
        loop variant remaining_x;
    */
    while (remaining_x >= 5)
    {
        //@ assert remaining_x >= 5;
        remaining_x -= 5;
        count_5 += 1;
        //@ assert remaining_x == x - 500 * count_500 - 5 * count_5;
    }
    
    //@ assert remaining_x == x - 500 * count_500 - 5 * count_5;
    result += count_5 * 5;
    
    //@ assert result == (((x) / 500) * 1000 + ((x) % 500 / 5) * 5);
    return result;
}

int main(void)
{
    return 0;
}
