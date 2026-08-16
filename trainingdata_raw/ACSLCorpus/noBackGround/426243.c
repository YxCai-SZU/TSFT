#include <stdint.h>
#include <limits.h>

/*@
    requires 1 <= n <= 1000000000;
    ensures \result == ((n) % 2 == 1 ? (n) * 2 : (n));
    ensures n % 2 == 1 ==> \result == n * 2;
    ensures n % 2 == 0 ==> \result == n;
*/
unsigned int func(unsigned int n) {
    unsigned int result;
    
    if (n % 2 == 1) {
        //@ assert n % 2 == 1;
        result = n * 2;
    } else {
        //@ assert n % 2 == 0;
        result = n;
    }
    
    return result;
}
