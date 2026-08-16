#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (((x) / 500) * 1000 + ((x) % 500 / 5) * 5);
    assigns \nothing;
*/
int32_t func(uint32_t x) {
    uint32_t result = 0;
    uint32_t temp_x = x;
    uint32_t count = 0;
    
    //@ assert (1 <= (x) <= 100000);
    //@ assert 0 <= temp_x <= x;
    //@ assert count == 0;
    
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant 0 <= count <= x / 500;
        loop invariant temp_x == x - count * 500;
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 500) {
        //@ assert temp_x >= 500;
        temp_x -= 500;
        count += 1;
        //@ assert temp_x == x - count * 500;
    }
    
    result += count * 1000;
    //@ assert result == (x / 500) * 1000;
    
    count = 0;
    //@ assert count == 0;
    
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant 0 <= count <= (x - temp_x) / 5;
        loop invariant temp_x == x - (result / 1000 * 500 + count * 5);
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 5) {
        //@ assert temp_x >= 5;
        temp_x -= 5;
        count += 1;
        //@ assert temp_x == x - (result / 1000 * 500 + count * 5);
    }
    
    result += count * 5;
    //@ assert result == (((x) / 500) * 1000 + ((x) % 500 / 5) * 5);
    
    //@ assert result <= 2147483647;
    return (int32_t)result;
}
