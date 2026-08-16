#include <stdint.h>

/*@
    requires (1 <= (a) <= 20 && 1 <= (b) <= 20);
    ensures ((a) <= 9 && (b) <= 9) ==> \result == ((a) * (b));
    ensures ((a) > 9 || (b) > 9) ==> \result == -1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t result;
    
    //@ assert (1 <= (a) <= 20 && 1 <= (b) <= 20);
    
    if (a > 9 || b > 9) {
        result = -1;
        //@ assert ((a) > 9 || (b) > 9);
    } else {
        //@ assert ((a) <= 9 && (b) <= 9);
        //@ assert ((a) * (b)) <= 81;
        result = (int32_t)a * (int32_t)b;
    }
    
    //@ assert (1 <= (a) <= 20 && 1 <= (b) <= 20);
    return result;
}
