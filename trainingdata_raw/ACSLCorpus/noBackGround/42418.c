#include <stdint.h>

/*@
    requires (1 <= (x) <= 1000000000);
    ensures \result >= 0;
    ensures \result <= x / 3;
    assigns \nothing;
*/
int32_t func(int32_t x)
{
    int32_t count = 0;
    int32_t value = x;
    
    /*@
        loop invariant ((1 <= ((x)) <= 1000000000) &&
        (value) >= 0 &&
        (count) >= 0 &&
        (value) == (x) - 3 * (count));
        loop assigns value, count;
        loop variant value;
    */
    while (value >= 3)
    {
        //@ assert value >= 3;
        value -= 3;
        count += 1;
        //@ assert value == x - 3 * count;
    }
    //@ assert value >= 0 && value < 3;
    //@ assert count >= 0;
    //@ assert count <= x / 3;
    return count;
}

int main(void)
{
    return 0;
}
