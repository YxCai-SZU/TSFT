#include <stdint.h>

/*@
    requires (1 <= (input) && (input) <= 1000000000);
    ensures \result <= input;
    ensures \result * 5 <= input;
*/
uint32_t func(uint32_t input)
{
    uint32_t count;
    uint32_t remaining;

    count = 0;
    remaining = input;

    /*@
        loop invariant ((1 <= ((input)) && ((input)) <= 1000000000) &&
        0 <= (count) && (count) <= (input) / 5 &&
        (remaining) == (input) - 5 * (count) &&
        (remaining) >= 0);
        loop assigns count, remaining;
        loop variant remaining;
    */
    while (remaining >= 5)
    {
        //@ assert remaining >= 5;
        remaining -= 5;
        count += 1;
        //@ assert remaining == input - 5 * count;
    }

    //@ assert count <= input;
    //@ assert count * 5 <= input;
    return count;
}
