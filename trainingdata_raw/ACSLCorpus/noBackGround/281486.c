#include <stdint.h>

/*@ requires 0 <= X <= 9 && 0 <= A <= 9;
    ensures (X < A ==> \result == 0) && (X >= A ==> \result == 10);
*/
uint32_t func(uint32_t X, uint32_t A)
{
    uint32_t result;
    
    //@ assert (0 <= (X) <= 9 && 0 <= (A) <= 9);
    
    if (X < A) {
        //@ assert X < A;
        result = 0;
    } else {
        //@ assert X >= A;
        result = 10;
    }
    
    //@ assert ((X) < (A) ? 0 : 10) == result;
    return result;
}
