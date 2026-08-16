#include <stdint.h>

/*@
    requires 1 <= a && a <= 10;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> ((a) == 5 || (a) == 3 || (a) == 7);
    ensures \result == 0 ==> !((a) == 5 || (a) == 3 || (a) == 7);
*/
int32_t func(uint64_t a)
{
    int32_t result;
    
    //@ assert a == a;
    
    if (a == 5 || a == 3 || a == 7) {
        //@ assert ((a) == 5 || (a) == 3 || (a) == 7);
        result = 1;
    } else {
        //@ assert !((a) == 5 || (a) == 3 || (a) == 7);
        result = 0;
    }
    
    return result;
}
