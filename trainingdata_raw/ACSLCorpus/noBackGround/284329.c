#include <stdint.h>

/*@
    requires 1 <= input <= 100000;
    ensures \result == 0 || \result == 1;
    ensures ((\result) == 1 ==> ((input) % 100) * 21 < (input));
    ensures ((\result) == 0 ==> ((input) % 100) * 21 >= (input));
*/
uint32_t func(uint32_t input)
{
    uint32_t n;
    uint32_t onedigit;
    uint32_t result;
    
    n = input % 100;
    onedigit = n * 21;
    
    if (onedigit < input)
    {
        //@ assert onedigit < input;
        result = 1;
    }
    else
    {
        //@ assert onedigit >= input;
        result = 0;
    }
    
    return result;
}
