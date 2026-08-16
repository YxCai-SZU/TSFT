#include <stdbool.h>
/*@
    requires 1 <= x && x <= 100000;
    ensures (((x) % 100) < 10) ==> \result == 1;
    ensures (((x) % 100) >= 10 && ((x) % 100) < 100) ==> \result == 0;
    ensures (((x) % 100) == 100 || ((x) % 100) > 100) ==> \result == 1;
*/
int func(unsigned int x) {
    int result;
    unsigned int mod_result;
    
    mod_result = x % 100;
    
    if (mod_result < 10) {
        //@ assert (((x) % 100) < 10);
        result = 1;
    } else if (mod_result < 100) {
        //@ assert (((x) % 100) >= 10 && ((x) % 100) < 100);
        result = 0;
    } else {
        //@ assert (((x) % 100) == 100 || ((x) % 100) > 100);
        result = 1;
    }
    
    return result;
}
