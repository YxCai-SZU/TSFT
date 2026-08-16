#include <stdint.h>

/*@
    predicate is_multiple_of_10(integer n) = n % 10 == 0;
    predicate is_not_multiple_of_10(integer n) = n % 10 != 0;
*/

/*@
    requires input <= 999;
    ensures is_multiple_of_10(input) ==> \result == 0;
    ensures is_not_multiple_of_10(input) ==> \result == 1;
*/
int32_t func(uint32_t input)
{
    uint32_t number;
    int32_t result;

    number = input;
    
    if (number % 10 == 0)
    {
        //@ assert is_multiple_of_10(number);
        result = 0;
    }
    else
    {
        //@ assert is_not_multiple_of_10(number);
        result = 1;
    }
    
    return result;
}
