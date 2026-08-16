#include <stdbool.h>

/*@
    predicate is_in_range(integer x) = 1 <= x <= 1000000000000;
    
    logic integer input_div_100(integer input) = input / 100;
    
    logic integer remainder_value(integer input, integer rem) = 
        input_div_100(input) - 5 * ((input_div_100(input) - rem) / 5);
*/

/*@
    requires is_in_range(input);
    ensures \result == ((input / 100) % 5 == 0);
*/
bool func(unsigned long long input)
{
    unsigned long long input_div_100;
    unsigned long long remainder;
    
    //@ assert is_in_range(input);
    
    input_div_100 = input / 100;
    remainder = input_div_100;
    
    /*@
        loop invariant 1 <= input <= 1000000000000;
        loop invariant remainder <= input_div_100;
        loop invariant remainder >= 0;
        loop invariant remainder == remainder_value(input, remainder);
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 5)
    {
        //@ assert remainder >= 5;
        remainder -= 5;
    }
    
    //@ assert remainder == input_div_100 % 5;
    return remainder == 0;
}
