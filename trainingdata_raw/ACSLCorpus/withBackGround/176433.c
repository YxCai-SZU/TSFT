#include <stdint.h>

/*@ predicate is_even(integer x) = x % 2 == 0; */

/*@
    requires 1 <= a <= 1000000000;
    ensures is_even(\result);
    ensures \result >= 2;
    ensures \result == a * 2 || \result == a;
*/
uint64_t func(uint64_t a)
{
    uint64_t result;
    
    if (a % 2 == 0) {
        result = a;
        //@ assert is_even(result);
    } else {
        //@ assert a * 2 >= 2;
        result = a * 2;
    }
    
    return result;
}
