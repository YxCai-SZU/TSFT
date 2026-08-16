#include <stdint.h>

/*@
    requires (0 <= (x) <= 9) && (0 <= (a) <= 9);
    ensures (x < a ==> \result == 0) && (x >= a ==> \result == 10);
    assigns \nothing;
*/
int32_t func(uint32_t x, uint32_t a)
{
    int32_t res;
    //@ assert (0 <= (x) <= 9) && (0 <= (a) <= 9);
    
    if (x < a) {
        //@ assert x < a ==> 0 == 0;
        res = 0;
    } else {
        //@ assert x >= a ==> 10 == 10;
        res = 10;
    }
    
    //@ assert (x < a ==> res == 0) && (x >= a ==> res == 10);
    return res;
}

int main() {
    return 0;
}
