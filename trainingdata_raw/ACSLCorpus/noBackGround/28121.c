#include <stdint.h>

/*@
    requires 1 <= input <= 100000;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> ((input % 100) * 21) <= input;
    ensures \result == 1 ==> ((input % 100) * 21) > input;
*/
int32_t func(uint32_t input)
{
    uint32_t n;
    uint32_t a;
    int32_t result;
    
    n = input / 100;
    a = input % 100;
    
    //@ assert (0 <= (a) <= 99);
    //@ assert ((a) * 21) <= 2079;
    
    if (a * 21 > input) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert result == 0 || result == 1;
    return result;
}
