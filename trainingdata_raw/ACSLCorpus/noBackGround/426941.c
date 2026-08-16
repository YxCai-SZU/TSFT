#include <stdbool.h>
/*@
    requires (1 <= (n) && 1 <= (k) && (n) <= 100 && (k) <= 100);
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> n % k == 0;
    ensures \result == 1 ==> n % k != 0;
*/
unsigned int func(unsigned int n, unsigned int k) {
    unsigned int result;
    //@ assert (1 <= (n) && 1 <= (k) && (n) <= 100 && (k) <= 100);
    
    if (n % k == 0) {
        //@ assert n % k == 0;
        result = 0;
    } else {
        //@ assert n % k != 0;
        result = 1;
    }
    
    //@ assert result == 0 || result == 1;
    //@ assert result == 0 ==> n % k == 0;
    //@ assert result == 1 ==> n % k != 0;
    return result;
}
