#include <stdint.h>

/*@
    predicate is_multiple_of_3(integer x) = x % 3 == 0;
    predicate not_multiple_of_3(integer x) = x % 3 != 0;
*/

/*@
    requires 1 <= x <= 100;
    ensures is_multiple_of_3(x) ==> \result == 1;
    ensures not_multiple_of_3(x) ==> \result == 0;
*/
int32_t func(uint32_t x)
{
    int32_t result;
    
    if (x % 3 == 0) {
        result = 1;
        //@ assert result == 1;
    } else {
        result = 0;
        //@ assert result == 0;
    }
    
    return result;
}
