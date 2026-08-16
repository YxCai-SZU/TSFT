#include <stdbool.h>
#include <stdint.h>

/*@
    requires 1 <= x <= 100;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> ((x) % 4 == 0 || (x) % 7 == 0 || (x) >= 4);
    ensures \result == 0 ==> !((x) % 4 == 0 || (x) % 7 == 0 || (x) >= 4);
*/
int func(unsigned int x) {
    int result;
    //@ assert 1 <= x <= 100;
    
    if (x % 4 == 0 || x % 7 == 0 || x >= 4) {
        //@ assert ((x) % 4 == 0 || (x) % 7 == 0 || (x) >= 4);
        result = 1;
    } else {
        //@ assert !((x) % 4 == 0 || (x) % 7 == 0 || (x) >= 4);
        result = 0;
    }
    
    return result;
}
