#include <stdint.h>

/*@
    requires (1 <= (a) <= 12 && 1 <= (b) <= 31);
    ensures \result == 0 || \result == 1;
    ensures \result == ((a) <= (b) ? 1 : 0);
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t answer;
    //@ assert (1 <= (a) <= 12 && 1 <= (b) <= 31);
    
    if (a <= b) {
        answer = 1;
        //@ assert answer == 1;
    } else {
        answer = 0;
        //@ assert answer == 0;
    }
    
    //@ assert answer == 0 || answer == 1;
    return answer;
}
