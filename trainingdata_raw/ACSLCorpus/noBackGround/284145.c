#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> ((a) % 3 == 0 || (b) % 3 == 0 || ((a) + (b)) % 3 == 0);
    ensures \result == 1 ==> !((a) % 3 == 0 || (b) % 3 == 0 || ((a) + (b)) % 3 == 0);
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t result;
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    
    if (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) {
        result = 0;
    } else {
        result = 1;
    }
    
    //@ assert result == 0 || result == 1;
    //@ assert result == 0 ==> ((a) % 3 == 0 || (b) % 3 == 0 || ((a) + (b)) % 3 == 0);
    //@ assert result == 1 ==> !((a) % 3 == 0 || (b) % 3 == 0 || ((a) + (b)) % 3 == 0);
    
    return result;
}
