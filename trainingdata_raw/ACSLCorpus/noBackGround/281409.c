#include <stdint.h>

/*@
    requires (1 <= (input) && (input) <= 1000000000000000);
    ensures \result >= 0;
    ensures \result <= 2 * input;
    assigns \nothing;
*/
int64_t func(int64_t input)
{
    uint64_t input_unsigned;
    uint64_t div = 0;
    uint64_t temp;
    int64_t result;
    
    if (input < 0) {
        input_unsigned = (uint64_t)(-input);
    } else {
        input_unsigned = (uint64_t)input;
    }
    
    temp = input_unsigned;
    
    /*@
        loop invariant 0 <= div <= input_unsigned / 11;
        loop invariant temp == input_unsigned - 11 * div;
        loop invariant temp >= 0;
        loop assigns div, temp;
        loop variant temp;
    */
    while (temp >= 11)
    {
        //@ assert temp >= 11;
        temp -= 11;
        div += 1;
        //@ assert temp == input_unsigned - 11 * div;
    }
    
    result = 2 * (int64_t)div;
    
    if (temp > 0 && temp <= 10) {
        result += 1;
    } else if (temp > 10) {
        result += 2;
    }
    
    if (input < 0) {
        result = -result;
    }
    
    //@ assert result >= 0;
    //@ assert result <= 2 * input;
    return result;
}
